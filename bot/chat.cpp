#include "chat.h"
#include "ui_chat.h"

chat::chat(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat)
{
    ui->setupUi(this);
    sbot = new SimpleBot();
    fontset = new class font();
}

chat::~chat()
{
    delete ui;
}

void chat::on_pushButton_clicked()
{
    ui->textEdit->setText(ui->textEdit->toPlainText()+
                          sbot->get_date()+" "+
                          sbot->get_time()+" "+
                          sbot->get_username()+": "+
                          ui->lineEdit->text()+'\n');
    ui->textEdit->setText(ui->textEdit->toPlainText()+
                          sbot->get_date()+" "+
                          sbot->get_time()+" "+
                          sbot->get_botname()+": "+
                          sbot->generate_answer(ui->lineEdit->text())+'\n');
    ui->lineEdit->setText("");
}

void chat::showEvent(QShowEvent *)
{
    // Настроить виджет из настроек
    ui->textEdit->setFont(fontset->get_textfont());
    ui->textEdit->setTextColor(fontset->get_textcolor());
    ui->textEdit->setFontPointSize(fontset->get_textsize());
    ui->lineEdit->setFont(fontset->get_textfont());

    file = new QFile("chat.txt");            // Создать новый файл или создать ссылку на существующий
    file->open(QIODevice::ReadOnly);         // Открыть файл
    ui->textEdit->setText(file->readAll());  // Считать данные из файла
    file->close();                           // Закрыть файл
}

void chat::closeEvent(QCloseEvent *)
{
    file = new QFile("chat.txt");            // Создать новый файл или создать ссылку на существующий
    file->open(QIODevice::WriteOnly);        // Открыть файл
    file->write(ui->textEdit->toPlainText().toStdString().c_str()); // Записать данные в файл
    file->close();                                                  // Закрыть файл
}
