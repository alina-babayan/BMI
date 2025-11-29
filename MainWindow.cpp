#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("BMI Calculator");
    this->setFixedSize(400, 350);

    QLabel* title = new QLabel("BMI Calculator", this);
    title->setGeometry(60, 10, 280, 40);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 22px; font-weight: bold;");

    weight = new QLabel("Weight (kg):", this);
    weight->setGeometry(30, 70, 100, 30);
    weight->setStyleSheet("font-size: 16px; font-weight: bold;");

    height = new QLabel("Height (m):", this);
    height->setGeometry(30, 110, 100, 30);
    height->setStyleSheet("font-size: 16px; font-weight: bold;");

    inputWeight = new QLineEdit(this);
    inputWeight->setGeometry(140, 70, 180, 30);
    inputWeight->setPlaceholderText("Enter your weight");

    inputHeight = new QLineEdit(this);
    inputHeight->setGeometry(140, 110, 180, 30);
    inputHeight->setPlaceholderText("Enter your height");

    calc = new QPushButton("Calculate BMI", this);
    calc->setGeometry(130, 160, 140, 32);
    calc->setStyleSheet("font-size: 14px;");

    displayVal = new QLabel("Your BMI:", this);
    displayVal->setGeometry(60, 220, 280, 30);
    displayVal->setAlignment(Qt::AlignCenter);
    displayVal->setStyleSheet("font-size: 18px; font-weight: bold;");

    displayCat = new QLabel("Category:", this);
    displayCat->setGeometry(60, 260, 280, 30);
    displayCat->setAlignment(Qt::AlignCenter);
    displayCat->setStyleSheet("font-size: 18px; font-weight: bold;");

    connect(calc, &QPushButton::clicked, this, &MainWindow::calculate);
}

void MainWindow::calculate()
{
    if (inputWeight->text().isEmpty() || inputHeight->text().isEmpty()) {
        displayVal->setText("Your BMI:");
        displayCat->setText("Category: Please enter values");
        return;
    }
    double weightVal = inputWeight->text().toDouble();
    double heightVal = inputHeight->text().toDouble();
    double BMI = weightVal / (heightVal * heightVal);

    displayVal->setText("Your BMI: " + QString::number(BMI));

    if (BMI < 18.5) displayCat->setText("Category: Underweight");
    else if (BMI < 25.0) displayCat->setText("Category: Normal weight");
    else if (BMI < 30.0) displayCat->setText("Category: Overweight");
    else displayCat->setText("Category: Obese");
}
