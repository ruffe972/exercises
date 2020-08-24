#pragma once
#include <array>
#include <memory>
#include <QDateTime>

// TaskPriority

enum class TaskPriority: int {
    Normal,
    Important,
    Urgent
};

const std::array<TaskPriority, 3> TASK_PRIORITIES = {
    TaskPriority::Normal,
    TaskPriority::Important,
    TaskPriority::Urgent
};

QString taskPriorityToString(TaskPriority priority);

// TaskType

enum class TaskType: int {
    Home,
    Work,
    Other
};

const std::array<TaskType, 3> TASK_TYPES = {
    TaskType::Home,
    TaskType::Work,
    TaskType::Other
};

QString taskTypeToString(TaskType type);

// TaskModel

static qint64 SECONDS_IN_HOUR = 60 * 60;

class TaskModel {
public:
    TaskModel(const QString &name = "",
              TaskPriority priority = TaskPriority::Normal,
              TaskType type = TaskType::Other,
              bool done = false,
              const QDateTime &dateTime = QDateTime::currentDateTime().addSecs(SECONDS_IN_HOUR));

    // Getters
    QString name() const;
    TaskPriority priority() const;
    TaskType type() const;
    bool done() const;
    QDateTime dateTime() const;

    void setDone(bool done);

private:
    QString _name;
    TaskPriority _priority;
    TaskType _type;
    bool _done;
    QDateTime _dateTime;
};
