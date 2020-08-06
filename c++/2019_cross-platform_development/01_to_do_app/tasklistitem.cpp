#include "tasklistitem.h"
#include "ui_tasklistitem.h"

#include "helpers.h"
#include "taskmodel.h"
#include <QDateTime>

static const int PRIORITY_INDICATOR_WIDTH = 10;

TaskListItem::TaskListItem(TaskModelPtr model, int globalTypeIndex, QWidget *parent) :
        QWidget(parent),
        _ui(new Ui::TaskListItem) {
    _ui->setupUi(this);
    _ui->priorityIndicator->setMinimumWidth(scaled(PRIORITY_INDICATOR_WIDTH));
    setModel(model, globalTypeIndex);
    connect(_ui->checkBox, &QCheckBox::clicked, [model](bool checked) {
        model->setDone(checked);
    });
}

TaskListItem::~TaskListItem() {
    delete _ui;
}

TaskModelPtr TaskListItem::model() const {
    return _model;
}

void TaskListItem::setModel(TaskModelPtr model, int globalTypeIndex) {
    _model = model;
    _ui->checkBox->setChecked(model->done());
    _ui->checkBox->setText(_model->name());
    _ui->timeLabel->setText(_model->dateTime().toString());
    auto priorityColor = color(_model->priority());
    _ui->priorityIndicator->setStyleSheet("background-color: " + priorityColor);
    updateVisibility(globalTypeIndex);
}

void TaskListItem::updateVisibility(int globalTypeIndex) {
    int taskTypeIndex = static_cast<int>(_model->type());
    setHidden((std::size_t)globalTypeIndex < TASK_TYPES.size() &&
              globalTypeIndex != taskTypeIndex);
}

QString TaskListItem::color(TaskPriority priority) {
    switch (priority) {
    case TaskPriority::Urgent:
        return "red";
    case TaskPriority::Important:
        return "orange";
    case TaskPriority::Normal:
        break;
    }
    return "green";
}
