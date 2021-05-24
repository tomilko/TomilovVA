#include "var.h"
#include "ui_var.h"

var::var(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::var)
{
    ui->setupUi(this);
}

var::~var()
{
    delete ui;
}

void var::on_pushButton_clicked()
{
 emit firstWindow();
 this->close();

}
