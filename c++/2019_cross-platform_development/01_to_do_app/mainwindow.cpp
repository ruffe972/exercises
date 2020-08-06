#include "mainwindow.h"
#include "mainwindowmodel.h"
#include "ui_mainwindow.h"
#include "edittaskwindow.h"
#include "helpers.h"
#include "tasklistitem.h"
#include "taskmodel.h"
#include <QDebug>
#include <QMenu>
#include <QStyleFactory>

static const auto WINDOW_SIZE = QSize(400, 400);
static const QString TASKS_AREA_COLOR = "white";

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        _ui(new Ui::MainWindow),
        _model(new MainWindowModel(this)),
        _defaultAppStyle(qApp->style()) {

    _ui->setupUi(this);

    initMenu();
    initTasksScrollArea();
    initTaskTypeComboBox();
    initConnections();

    setFixedSize(scaled(WINDOW_SIZE));

    _ui->newTaskButton->setFocus();
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::initMenu() {
    // Fix for Fusion theme
    setStyleSheet("QToolButton::menu-indicator { image: none; }");

    auto menu = new QMenu(this);

    menu->addAction("Save Tasks to File", this, &MainWindow::saveTasks);
    menu->addAction("Load Tasks from File", this, &MainWindow::loadTasks);

    auto toggleThemeAction = menu->addAction("Fusion Theme");
    toggleThemeAction->setCheckable(true);
    connect(toggleThemeAction, &QAction::toggled, this, &MainWindow::toggleCustomTheme);

//    _toggleSoundAction = menu->addAction("Sound Notifications");
//    _toggleSoundAction->setCheckable(true);
//    _toggleSoundAction->setChecked(true);

    _ui->menuButton->setMenu(menu);
}

void MainWindow::initTasksScrollArea() {
    _ui->tasksContainer->setStyleSheet("background-color: " + TASKS_AREA_COLOR);

    _tasksLayout = new QVBoxLayout;
    _ui->tasksContainer->setLayout(_tasksLayout);
    auto spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Expanding);
    _tasksLayout->addItem(spacer);
}

void MainWindow::initTaskTypeComboBox() {
    auto comboBox = _ui->taskTypeComboBox;
    for (auto type: TASK_TYPES) {
        comboBox->addItem(taskTypeToString(type));
    }
    // This item should be the last
    comboBox->addItem("Any Type");
    comboBox->setCurrentIndex(comboBox->count() - 1);
}

void MainWindow::initConnections() {
    connect(_ui->newTaskButton, &QAbstractButton::clicked, this, &MainWindow::addNewTask);
}

void MainWindow::saveTasks() {
    std::vector<TaskModelPtr> tasks;
    for (auto taskWidget: taskWidgets()) {
        tasks.push_back(taskWidget->model());
    }
    _model->saveToFile(tasks);
}

void MainWindow::loadTasks() {
    for (auto taskWidget: taskWidgets()) {
        delete taskWidget;
    }
    auto tasks = _model->loadTasksFromFile();
    for (auto task: tasks) {
        addTaskWidget(task);
    }
}

QList<TaskListItem *> MainWindow::taskWidgets() {
    return _ui->tasksContainer->findChildren<TaskListItem *>();
}

void MainWindow::addTaskWidget(TaskModelPtr taskModel) {
    auto taskWidget = new TaskListItem(taskModel, _ui->taskTypeComboBox->currentIndex());
    _tasksLayout->insertWidget(0, taskWidget);
    connect(taskWidget, &QWidget::customContextMenuRequested, this, &MainWindow::showTaskMenu);
    connect(_ui->taskTypeComboBox,
            SIGNAL(currentIndexChanged(int)),
            taskWidget,
            SLOT(updateVisibility(int)));
}

void MainWindow::toggleCustomTheme(bool enabled) {
    if (enabled) {
        // Keep the default theme object alive
        _defaultAppStyle->setParent(this);

        qApp->setStyle(QStyleFactory::create("fusion"));
    } else {
        qApp->setStyle(_defaultAppStyle);
    }
}

void MainWindow::addNewTask() {
    auto dialog = new EditTaskWindow("New Task",
                                     TaskModelPtr(new TaskModel),
                                     this);
    if (dialog->exec() == QDialog::Accepted) {
        addTaskWidget(dialog->model());
    }
}

void MainWindow::showTaskMenu(const QPoint &pos) {
    QMenu menu;
    auto taskWidget = static_cast<TaskListItem *>(sender());
    menu.addAction("Edit Task", [this, taskWidget] {
        auto dialog = new EditTaskWindow("Edit Task",
                                         taskWidget->model(),
                                         this);
        if (dialog->exec() == QDialog::Accepted) {
            taskWidget->setModel(dialog->model(), _ui->taskTypeComboBox->currentIndex());
        }
    });
    menu.addAction("Delete Task", [taskWidget] {
        delete taskWidget;
    });
    menu.exec(taskWidget->mapToGlobal(pos));
}
