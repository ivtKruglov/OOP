    #ifndef SIMPLEBOT_H
#define SIMPLEBOT_H

#include <QDebug>
#include <QMultiMap>
#include <QRegExp>
#include <QVector>
#include <QTime>
#include <QDate>
#include <qglobal.h>

class SimpleBot
{
private:
    QMultiMap<QString, QString> user_dict;              // Словарь регулярных выражений для пользователя
    QMultiMap<QString, QString> answers;                // Словарь с ответами бота
    QString username;                                   // Имя пользователя
    QString botname;                                    // Имя бота
    QDate date = QDate::currentDate();                  // Текущая дата
    QTime time = QTime::currentTime();                  // Текущее время

public:
    SimpleBot();
    void set_username(const QString &name);             // Сохранить имя пользователя
    const QString get_username();                       // Вернуть имя пользователя
    const QString get_botname();                        // Вернуть имя бота
    const QString get_time();                           // Вернуть время
    const QString get_date();                           // Вернуть дату
    QString generate_answer(const QString &msg);        // Создание ответа по ключу, соответствующему сообщению
    QString search_key(const QString &msg, QMultiMap<QString, QString> &dict); // Поиск ключа регулярного выражения, соответствующего сообщению пользователя
    double calculate(const QString &key, const QString &msg, QMultiMap<QString, QString> &dict); // Вычисление арифметических операций
};

#endif // SIMPLEBOT_H
