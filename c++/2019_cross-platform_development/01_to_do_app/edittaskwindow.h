#pragma once
#include "pointers.h"
#include <QDialog>

namespace Ui {
class EditTaskWindow;
}

class TaskModel;

class EditTaskWindow : public QDialog {
    Q_OBJECT
public:
    explicit EditTaskWindow(const QString &windowTitle,
                            TaskModelPtr model,
                            QWidget *parent = 0);
    TaskModelPtr model();
    ~EditTaskWindow();
private:
    void initWithModel(TaskModelPtr model);
    void initComboboxes();
    QDateTime removedSeconds(const QDateTime &dateTime);
private:
    Ui::EditTaskWindow *_ui;
};
