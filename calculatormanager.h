#ifndef CALCULATORMANAGER_H
#define CALCULATORMANAGER_H

#include <QLineEdit>
#include <string>

enum KIND
{
    NUMBER,
    OPERATOR
};

class CalculatorManager
{
private:
    int current_value;
    bool adding_numbers;
    std::string numbers = "1234567890";
    std::string operators = "+-*/";

    enum KIND check_char(char c);

public:
    CalculatorManager();

    void calculate(char c, QLineEdit edt);
};

#endif // CALCULATORMANAGER_H
