#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "drawingarea.h"
#include <QWidget>
#include <QLayout>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    DrawingArea *_drawingArea;
    void addButtons(QVBoxLayout *layout);
};

#endif // MAINWINDOW_H
