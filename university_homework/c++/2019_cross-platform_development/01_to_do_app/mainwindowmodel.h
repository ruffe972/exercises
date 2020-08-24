#pragma once
#include <QObject>
#include "pointers.h"

class MainWindowModel : public QObject {
    Q_OBJECT
public:
    explicit MainWindowModel(QObject *parent = nullptr);
    std::vector<TaskModelPtr> loadTasksFromFile() const;
    void saveToFile(const std::vector<TaskModelPtr> &tasks) const;
};
