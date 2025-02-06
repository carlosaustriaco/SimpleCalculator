#include "calculatormanager.h"

#include <algorithm>

CalculatorManager::CalculatorManager()
{
    this->current_value = 0;
    this->adding_numbers = true;
}

void CalculatorManager::calculate(char c, QLineEdit edt)
{
    enum KIND char_kind = this->check_char(c);
}

enum KIND CalculatorManager::check_char(char c)
{
    if (std::find(this->numbers.begin(), this->numbers.end(), c) != this->numbers.end())
    {
        return NUMBER;
    }

    return OPERATOR;
}
