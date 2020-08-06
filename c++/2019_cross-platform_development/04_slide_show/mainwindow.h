#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QStringList>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void timerEvent(QTimerEvent *event) override;

private:
    void openImage();
    void updateImage(const QString &imageName);
    void updateImage(int posInList);

private:
    Ui::MainWindow *ui;
    QGraphicsScene scene;
    QStringList imageFileNameList;
    int imagePosInList = 0;
    int timerId = 0;
};

#endif // MAINWINDOW_H
