#include "mainwindow.h"
#include <QPushButton>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
      _drawingArea(nullptr)
{
    setFixedSize(800, 600);
    auto layout = new QVBoxLayout;
    setLayout(layout);

    auto label = new QLabel;
    _drawingArea = new DrawingArea(label);
    _drawingArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(_drawingArea);

    label->setAlignment(Qt::AlignCenter);
    layout->addWidget(label);

    addButtons(layout);
}

void MainWindow::addButtons(QVBoxLayout *layout)
{
    auto buttonLayout = new QHBoxLayout;
    layout->addLayout(buttonLayout);

    auto resetButton = new QPushButton("Reset");
    buttonLayout->addWidget(resetButton);
    QObject::connect(resetButton, &QPushButton::clicked, _drawingArea, &DrawingArea::resetAndAddShapes);

    auto sortButton = new QPushButton("Sort");
    buttonLayout->addWidget(sortButton);
    QObject::connect(sortButton, &QPushButton::clicked, _drawingArea, &DrawingArea::sortShapes);

    auto fillButton = new QPushButton("Random fill");
    buttonLayout->addWidget(fillButton);
    QObject::connect(fillButton, &QPushButton::clicked, _drawingArea, &DrawingArea::randomFill);
}
