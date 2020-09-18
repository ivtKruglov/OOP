#ifndef FONT_H
#define FONT_H

#include <QFont>
#include <QColor>

class font
{
private:
    QFont textfont;      // Шрифт
    QColor textcolor;    // Цвет шрифта
    qreal textsize;      // Размер шрифта
public:
    font();
    QFont get_textfont();              // Вернуть шрифт текста
    QColor get_textcolor();            // Вернуть цвет текста
    qreal get_textsize();              // Вернуть размер текста
    void set_textfont(QFont font);     // Задать шрифт текста
    void set_textcolor(QColor color);  // Задать цвет текста
    void set_textsize(qreal size);     // Задать размер текста
};

#endif // FONT_H
