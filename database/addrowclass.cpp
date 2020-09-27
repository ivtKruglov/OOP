#include "addrowclass.h"
#include "ui_addrowclass.h"

AddRowClass::AddRowClass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowClass)
{
    ui->setupUi(this);
}

AddRowClass::~AddRowClass()
{
    delete ui;
}
void AddRowClass::on_addRow_clicked()
{
    emit checkData();
}

void AddRowClass::on_cancel_clicked()
{
    this->close();
}

void AddRowClass::incorrectData()
{
    ui->label_5->setText("Неверный формат данных!");
}

QVector<QString> AddRowClass::getNewRow()
{
    return {ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text(), ui->lineEdit_4->text()};
}
