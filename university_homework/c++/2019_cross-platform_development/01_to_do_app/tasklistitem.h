#pragma once

#include <QWidget>
#include "pointers.h"

enum class TaskPriority;

namespace Ui {
class TaskListItem;
}

class TaskListItem : public QWidget {
    Q_OBJECT
public:
    explicit TaskListItem(TaskModelPtr model, int globalTypeIndex, QWidget *parent = 0);
    ~TaskListItem();
    TaskModelPtr model() const;
    void setModel(TaskModelPtr model, int globalTypeIndex);
public slots:
    void updateVisibility(int globalTypeIndex);
private:
    static QString color(TaskPriority priority);
private:
    Ui::TaskListItem *_ui;
    TaskModelPtr _model;
};
