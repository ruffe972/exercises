#include "edittaskwindow.h"
#include "ui_edittaskwindow.h"

#include "helpers.h"
#include "taskmodel.h"
#include <QAbstractButton>
#include <QDebug>

static const int PLANE_ICON_SIZE = 24;

EditTaskWindow::EditTaskWindow(const QString &windowTitle,
                               TaskModelPtr model,
                               QWidget *parent) :
        QDialog(parent),
        _ui(new Ui::EditTaskWindow) {

    _ui->setupUi(this);
    _ui->okButton->setIconSize(scaled(QSize(PLANE_ICON_SIZE, PLANE_ICON_SIZE)));
    setWindowTitle(windowTitle);

    connect(_ui->okButton, &QAbstractButton::clicked, this, &QDialog::accept);
    connect(_ui->taskName, &QLineEdit::returnPressed, this, &QDialog::accept);

    initComboboxes();
    initWithModel(model);

    resize(minimumSizeHint());
    setFixedHeight(height());
}

TaskModelPtr EditTaskWindow::model() {
    auto dateTime = removedSeconds(_ui->dateTimeEdit->dateTime());
    auto priority = static_cast<TaskPriority>(_ui->priority->currentIndex());
    auto type = static_cast<TaskType>(_ui->type->currentIndex());
    return TaskModelPtr(new TaskModel(_ui->taskName->text(),
                                      priority,
                                      type,
                                      false,
                                      dateTime));
}

EditTaskWindow::~EditTaskWindow() {
    delete _ui;
}

void EditTaskWindow::initWithModel(TaskModelPtr model) {
    _ui->taskName->setText(model->name());
    _ui->dateTimeEdit->setDateTime(model->dateTime());

    int priorityNumber = static_cast<int>(model->priority());
    _ui->priority->setCurrentIndex(priorityNumber);

    int typeNumber = static_cast<int>(model->type());
    _ui->type->setCurrentIndex(typeNumber);
}

void EditTaskWindow::initComboboxes() {
    for (auto priority: TASK_PRIORITIES) {
        _ui->priority->addItem(taskPriorityToString(priority));
    }
    for (auto type: TASK_TYPES) {
        _ui->type->addItem(taskTypeToString(type));
    }
}

QDateTime EditTaskWindow::removedSeconds(const QDateTime &dateTime) {
    auto time = dateTime.time();
    return QDateTime(dateTime.date(),
                     QTime(time.hour(), time.minute()));
}
