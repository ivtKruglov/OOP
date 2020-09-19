#include "calculator.h"

Calculator::Calculator()
{

}

void Calculator::SetValue(double value)
{
    this->_value=value;
}

double Calculator::GetValue()
{
    return this->_value;
}

void Calculator::operator+=(double value)
{
    this->SetValue(this->_value+value);
}

void Calculator::operator-=(double value)
{
    this->SetValue(this->_value-value);
}

void Calculator::operator*=(double value)
{
    this->SetValue(this->_value*value);
}

void Calculator::operator/=(double value)
{
    if(value != 0)
        this->SetValue(this->_value/value);
}

double Calculator::sinValue()
{
    return sin(this->_value);
}

double Calculator::cosValue()
{
    return cos(this->_value);
}

double Calculator::tgValue()
{
    return tan(this->_value);
}

double Calculator::ctgValue()
{
    return cos(this->_value)/sin(this->_value);
}

double Calculator::expValue()
{
    return exp(this->_value);
}

double Calculator::lnValue()
{
    return log(this->_value);
}

double Calculator::sqrtValue()
{
    return sqrt(this->_value);
}

double Calculator::sqrValue()
{
    return this->_value*this->_value;
}
