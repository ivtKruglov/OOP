#ifndef CHAT_H
#define CHAT_H

#include <QDialog>
#include <QFile>
#include "simplebot.h"
#include "settings.h"

namespace Ui {
class chat;
}

class chat : public QDialog
{
    Q_OBJECT

public:
    explicit chat(QWidget *parent = nullptr);
    ~chat();
    SimpleBot *sbot;                 // Класс с логикой работы бота
    class font *fontset;             // Класс, содержащий настройки текста

private slots:
    void on_pushButton_clicked();    // Отправить сообщение боту
    void closeEvent(QCloseEvent *);  // Переопределение метода закрытия окна
    void showEvent(QShowEvent *);    // Переопределение метода открытия окна

private:
    Ui::chat *ui;
    QFile *file;
};

#endif // CHAT_H
