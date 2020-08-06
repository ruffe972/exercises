#pragma once
#include <QMainWindow>


namespace Ui
{
    class Calculator;
}

//! Calculator/main window
class Calculator : public QMainWindow
{
    Q_OBJECT    
public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();        
private:
    double calculate(int left, char operation, int right) const;
    Ui::Calculator *ui;    
private slots:
    void updateResult();
};
