#include "newdbclass.h"
#include "ui_newdbclass.h"

NewDBClass::NewDBClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewDBClass)
{
    ui->setupUi(this);
}

NewDBClass::~NewDBClass()
{
    delete ui;
}

void NewDBClass::on_ok_clicked()
{
    if (ui->lineEdit->text() == "")
        ui->label_2->setText("Не задано имя базы данных!");
    else
    {
        bdname = ui->lineEdit->text();
        emit created();
        this->close();
    }
}

void NewDBClass::on_cancel_clicked()
{
    this->close();
}

QString NewDBClass::bdName()
{
    return bdname;
}
