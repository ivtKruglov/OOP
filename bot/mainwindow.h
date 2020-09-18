#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "chat.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Settings *settings;                    // Класс окна настроек
    chat *newchat;                         // Класс окна чата

private slots:
    void on_pushButton_clicked();          // Открыть окно чата
    void on_pushButton_2_clicked();        // Открыть окно настроек

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
