#include "dbclass.h"

DBClass::DBClass()
{
    columnSize = 5;
    dict =
    {
        {0, "\\b(?:\\S+)\\b"},                                                   // Марка
        {1, "\\b(?:\\d+)\\b"},                                                   // Мощность (в л.с.)
    };
    headers.append("ID");
    headers.append("Марка");
    headers.append("Мощность (в л.с.)");
    headers.append("Тип коробки передач");
    headers.append("Тип машины");
}

void DBClass::addRow(const QVector<QString> &row)
{
    QVector<QString> currentRow = row;
    if (row.size() != columnSize)
    {
        int id = data.size() + 1;
        currentRow.prepend(QString::number(id));
    }
    data.append(currentRow);
}

void DBClass::removeRow(const int &id)
{
    for (int indexRow = 0; indexRow < data.size(); ++indexRow)
    {
        if (data[indexRow][0].toInt() == id)
            data.remove(indexRow);
    }
}

void DBClass::sort()
{
    QVector<QString> temp;
    for (int rowIndex = 0; rowIndex < data.size(); ++rowIndex)
    {
        for (int nextRowIndex = rowIndex; nextRowIndex < data.size(); ++nextRowIndex)
        {
            if (strcmp(data[rowIndex][1].toStdString().c_str(), data[nextRowIndex][1].toStdString().c_str()) > 0)
            {
                temp = data[rowIndex];
                data[rowIndex] = data[nextRowIndex];
                data[nextRowIndex] = temp;
            }
        }
    }
}

void DBClass::clear()
{
    data.clear();
}

bool DBClass::checkRow(const QVector<QString> &row)
{
    bool result = true;
    for (int i = 0; i < row.size()-2; ++i)
    {
        QRegExp rx(dict.values(i).value(0));
        if (rx.indexIn(row[i]) != -1)
        {
            if (i == 1)
            {
                if (row[i].toInt() > 3750 || row[i].toInt() < 100)
                    result = false;
                else
                    result = true;
            }
            else
                result = true;
        }
        else
            result = false;
        if (!result)
            break;
    }
    return result;
}

void DBClass::newData(const QVector<QVector<QString>> &newdata)
{
    data = newdata;
}

void DBClass::newName(const QString &newname)
{
    name = newname;
}

const QVector<QVector<QString>> DBClass::getRows()
{
    return data;
}

const QStringList DBClass::getHeaders()
{
    return headers;
}

const QString DBClass::getName()
{
    return name;
}

int DBClass::getColumnSize()
{
    return columnSize;
}
