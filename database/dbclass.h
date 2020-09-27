#ifndef DBCLASS_H
#define DBCLASS_H
#include <QVector>
#include <QMap>
#include <QDebug>

class DBClass
{
private:
    QVector<QVector<QString>> data;
    QMap<int, QString> dict;
    QStringList headers;
    QString name;
    int columnSize;

public:
    DBClass();
    void addRow(const QVector<QString> &row);
    void removeRow(const int &id);
    void sort();
    void clear();
    bool checkRow(const QVector<QString> &row);
    void newData(const QVector<QVector<QString>> &newdata);
    void newName(const QString &newname);
    const QVector<QVector<QString>> getRows();
    const QStringList getHeaders();
    const QString getName();
    int getColumnSize();

};

#endif // DBCLASS_H
