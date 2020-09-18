#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    settings = new Settings();                                 // Создать окно настроек
    newchat = new chat(); // Создать окно чата

    connect(settings, SIGNAL(openmain()), this, SLOT(show())); // Соединить сигнал и слот
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->textEdit->toPlainText() == "")
    {
        QMessageBox::warning(this, "Ошибка", "Не задано имя пользователя!"); // Открыть окно с предупреждением
    }
    else
    {
       newchat->fontset->set_textfont(settings->fontset->get_textfont());
       newchat->fontset->set_textsize(settings->fontset->get_textsize());
       newchat->fontset->set_textcolor(settings->fontset->get_textcolor());
       newchat->sbot->set_username(ui->textEdit->toPlainText());
       newchat->show();            // Показать окно
       this->close();              // Закрыть главное окно
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    settings->show();              // Показать окно настроек
    this->close();                 // Закрыть главное окно
}
