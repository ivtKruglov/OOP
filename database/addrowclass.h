#ifndef ADDROWCLASS_H
#define ADDROWCLASS_H

#include <QDialog>

namespace Ui {
class AddRowClass;
}

class AddRowClass : public QDialog
{
    Q_OBJECT

public:
    explicit AddRowClass(QWidget *parent = nullptr);
    ~AddRowClass();
    QVector<QString> getNewRow();

private slots:
    void on_addRow_clicked();
    void on_cancel_clicked();
    void incorrectData();

signals:
    void checkData();

private:
    Ui::AddRowClass *ui;
};

#endif // ADDROWCLASS_H
