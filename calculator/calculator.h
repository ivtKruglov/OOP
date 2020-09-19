#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "math.h"

class Calculator
{
private:
    double _value; // Значение в калькуляторе

public:
    Calculator();
    void SetValue(double value); // Установка значения
    double GetValue(); // Получение значения
    void operator +=(double value); // Оператор сложения
    void operator -=(double value); // Оператор вычитания
    void operator *=(double value); // Оператор умножения
    void operator /=(double value); // Оператор деления
    double expValue(); // exp
    double sqrtValue(); // sqrt
    double sqrValue();
    double lnValue(); // ln
    double sinValue(); // sin
    double cosValue(); // cos
    double tgValue(); // tg
    double ctgValue(); // ctg
};

#endif // CALCULATOR_H
