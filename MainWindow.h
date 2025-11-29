#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>

class MainWindow: public QMainWindow
{
    Q_OBJECT
public:
    MainWindow (QWidget * parent = nullptr);
private slots:
    void calculate();
private:
    QLabel* weight;
    QLabel* height;
    QLabel* result;
    QLabel* displayVal;
    QLabel* displayCat;
    QLineEdit* inputWeight;
    QLineEdit* inputHeight;
    QPushButton* calc;
};

#endif // MAINWINDOW_H
