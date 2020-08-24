#include "taskmodel.h"
#include <QDebug>

TaskModel::TaskModel(const QString &name, TaskPriority priority,
                     TaskType type,
                     bool done,
                     const QDateTime &time) :
        _name(name),
        _priority(priority),
        _type(type),
        _done(done),
        _dateTime(time) {
}

QString TaskModel::name() const {
    return _name;
}

TaskPriority TaskModel::priority() const {
    return _priority;
}

TaskType TaskModel::type() const {
    return _type;
}

bool TaskModel::done() const {
    return _done;
}

QDateTime TaskModel::dateTime() const {
    return _dateTime;
}

void TaskModel::setDone(bool done) {
    _done = done;
}

QString taskPriorityToString(TaskPriority priority) {
    switch (priority) {
    case TaskPriority::Important:
        return "Important";
    case TaskPriority::Normal:
        return "Normal";
    case TaskPriority::Urgent:
        break;
    }
    return "Urgent";
}

QString taskTypeToString(TaskType type) {
    switch (type) {
    case TaskType::Home:
        return "Home";
    case TaskType::Other:
        return "Other";
    case TaskType::Work:
        break;
    }
    return "Work";
}
