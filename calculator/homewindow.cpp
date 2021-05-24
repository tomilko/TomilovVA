#include "homewindow.h"
#include "ui_homewindow.h"

homewindow::homewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::homewindow)
{
    ui->setupUi(this);
    calculatorWindow = new MainWindow();
}

homewindow::~homewindow()
{
    delete ui;
}

void homewindow::on_pushButton_clicked()
{
    calculatorWindow->show();
    this->close();
}
