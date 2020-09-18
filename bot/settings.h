#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "font.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Settings(QWidget *parent = nullptr);
    ~Settings();
    class font *fontset;

private slots:
    void on_pushButton_clicked();   // Применить
    void on_pushButton_2_clicked(); // Отмена

signals:
    void openmain();                // Открыть главное окно

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
