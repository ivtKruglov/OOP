#include "font.h"

font::font()
{
    textfont = QFont("Calibri");
    textsize = 10;
    textcolor = QColor("black");
}

QFont font::get_textfont()
{
    return textfont;
}

qreal font::get_textsize()
{
    return textsize;
}

QColor font::get_textcolor()
{
    return textcolor;
}

void font::set_textfont(QFont font)
{
    textfont = font;
}

void font::set_textcolor(QColor color)
{
    textcolor = color;
}

void font::set_textsize(qreal size)
{
    textsize = size;
}
