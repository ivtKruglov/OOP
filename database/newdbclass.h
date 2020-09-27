#ifndef NEWDBCLASS_H
#define NEWDBCLASS_H

#include <QDialog>

namespace Ui {
class NewDBClass;
}

class NewDBClass : public QDialog
{
    Q_OBJECT

public:
    explicit NewDBClass(QWidget *parent = nullptr);
    ~NewDBClass();
    QString bdName();

private slots:
    void on_ok_clicked();
    void on_cancel_clicked();

signals:
    void created();

private:
    Ui::NewDBClass *ui;
    QString bdname;
};

#endif // NEWDBCLASS_H
