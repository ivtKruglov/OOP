#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QCloseEvent>
#include "dbclass.h"
#include "addrowclass.h"
#include "newdbclass.h"
#include "warningclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DataBase; }
QT_END_NAMESPACE

class DataBase : public QMainWindow
{
    Q_OBJECT

public:
    DataBase(QWidget *parent = nullptr);
    ~DataBase();

private slots:
    void closeEvent(QCloseEvent *event);
    void created();
    void on_addrow_clicked();
    void on_removerow_clicked();
    void on_sort_clicked();
    void on_clear_clicked();
    void on_search_clicked();
    void on_newbd_triggered();
    void on_openbd_triggered();
    void on_savebd_triggered();
    void on_exit_triggered();
    QVector<QVector<QString>> readFile(QFile &f);
    void writeFile(QFile &f, const QVector<QVector<QString> > &data);
    void updateTable();
    //void addRowToTable();
    void checkData();

signals:
    void OK();
    void error();

private:
    Ui::DataBase *ui;
    AddRowClass *addRowWindow;
    NewDBClass *createWindow;
    WarningClass *msgWindow;
    DBClass database;
    bool isCreated;
};
#endif // DATABASE_H
