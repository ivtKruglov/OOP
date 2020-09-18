#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    fontset = new class font();
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{
    fontset->set_textfont(ui->fontComboBox->currentFont());
    fontset->set_textsize(ui->comboBox_2->currentText().toDouble());
    fontset->set_textcolor(ui->comboBox->currentText());
    emit openmain();    // Отправить сигнал
    this->close();      // Закрыть окно настроек
}

void Settings::on_pushButton_2_clicked()
{
    emit openmain();    // Отправить сигнал
    this->close();      // Закрыть окно настроек
}
