#include "calculatormanager.h"

#include <algorithm>
#include <QString>

CalculatorManager::CalculatorManager()
{
    this->current_value ="";
    this->op_kind = NONE;
    this->older_kind = NONE;
}

void CalculatorManager::calculate(QChar c, QLineEdit *edt)
{
    enum KIND char_kind = this->check_char(c);

    switch(char_kind)
    {
    case NUMBER:
        this->add_number(c, edt);
        break;

    case OPERATOR:
        this->add_operator(c, edt);
        break;
    }
}

void CalculatorManager::add_operator(QChar c, QLineEdit *edt)
{
    if (c == '+')
    {
        this->op_kind = SUM;
    }
    else if (c == '-')
    {
        this->op_kind = SUBTRACTION;
    }
    else if (c == 'X')
    {
        this->op_kind = MULTIPLICATION;
    }
    else if (c == '/')
    {
        this->op_kind = DIVISION;
    }
    else if (c == '=')
    {
        this->add_result(c, edt);
    }
}

void CalculatorManager::add_number(QChar c, QLineEdit *edt)
{
    if(this->op_kind == NONE)
    {
        this->current_value += c;
        edt->setText(this->current_value);
    }
    else{
        this->older_kind = this->op_kind;
        this->op_kind = NONE;
        this->older_value = this->current_value;
        this->current_value = QString(c);
        edt->setText(this->current_value);
    }
}

void CalculatorManager::add_result(QChar c, QLineEdit *edt)
{
    qint32 i_older_value = this->older_value.toInt();
    qint32 i_current_value = this->current_value.toInt();
    qint32 i_result_value;

    switch(this->older_kind)
    {
    case SUM:
        i_result_value = i_older_value + i_current_value;
        break;

    case SUBTRACTION:
        i_result_value = i_older_value - i_current_value;
        break;

    case MULTIPLICATION:
        i_result_value = i_older_value * i_current_value;
        break;

    case DIVISION:
        i_result_value = i_older_value / i_current_value;
        break;
    }

    this->current_value = QString::number(i_result_value);
    edt->setText(this->current_value);
    this->older_kind = NONE;
    this->op_kind = NONE;
}

enum KIND CalculatorManager::check_char(QChar c)
{
    if (std::find(this->numbers.begin(), this->numbers.end(), c) != this->numbers.end())
    {
        return NUMBER;
    }

    return OPERATOR;
}
