#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void updateTranslation();
    void initTranslitTable();
    Ui::MainWindow *ui;
    QHash<QChar, QString> translitTable;
};

#endif // MAINWINDOW_H
