#pragma once
#include "pointers.h"
#include <QMainWindow>

class MainWindowModel;
class QVBoxLayout;
class TaskListItem;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void initMenu();
    void initTasksScrollArea();
    void initTaskTypeComboBox();
    void initConnections();
    void saveTasks();
    void loadTasks();
    QList<TaskListItem *> taskWidgets();
    void addTaskWidget(TaskModelPtr taskModel);
private slots:
    void addNewTask();
    void toggleCustomTheme(bool enabled);
    void showTaskMenu(const QPoint &pos);
private:
    Ui::MainWindow *_ui;
    MainWindowModel *_model;
    QStyle *_defaultAppStyle;
    QAction *_toggleSoundAction = nullptr;
    QVBoxLayout *_tasksLayout = nullptr;
};
