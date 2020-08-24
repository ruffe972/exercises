#include "mainwindowmodel.h"

#include "taskmodel.h"
#include <QDataStream>
#include <QFile>

MainWindowModel::MainWindowModel(QObject *parent) : QObject(parent) {

}

std::vector<TaskModelPtr> MainWindowModel::loadTasksFromFile() const {
    QFile file("tasks.dat");
    file.open(QIODevice::ReadOnly);
    QDataStream in(&file);
    quint64 tasksAmount = 0;
    in >> tasksAmount;
    std::vector<TaskModelPtr> tasks;

    for (quint64 i = 0; i < tasksAmount; i++) {
        QString name;
        qint8 priorityIndex;
        qint8 typeIndex;
        bool done;
        QDateTime dateTime;
        in >> name >> priorityIndex >> typeIndex >> done >> dateTime;
        tasks.push_back(TaskModelPtr(new TaskModel(name,
                                                   static_cast<TaskPriority>(priorityIndex),
                                                   static_cast<TaskType>(typeIndex),
                                                   done,
                                                   dateTime)));
    }
    return tasks;
}

void MainWindowModel::saveToFile(const std::vector<TaskModelPtr> &tasks) const {
    QFile file("tasks.dat");
    file.open(QIODevice::WriteOnly);
    QDataStream out(&file);
    out << (quint64)(tasks.size());
    for (auto task: tasks) {
        out << task->name()
               << (qint8)(task->priority())
               << (qint8)(task->type())
               << task->done()
               << task->dateTime();
    }
}
