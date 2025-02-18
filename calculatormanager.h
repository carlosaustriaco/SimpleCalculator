#ifndef CALCULATORMANAGER_H
#define CALCULATORMANAGER_H

#include <QLineEdit>
#include <QString>

enum KIND
{
    NUMBER,
    OPERATOR,
};

enum OPERATION_KIND
{
    SUM,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    NONE
};

class CalculatorManager
{
private:
    QString current_value;
    QString older_value;
    enum OPERATION_KIND op_kind;
    enum OPERATION_KIND older_kind;
    QString numbers = "1234567890";
    QString operators = "+-*/=";

    enum KIND check_char(QChar c);
    void add_number(QChar c, QLineEdit *edt);
    void add_operator(QChar c, QLineEdit *edt);
    void add_result(QChar c, QLineEdit *edt);

public:
    CalculatorManager();

    void calculate(QChar c, QLineEdit *edt);
};

#endif // CALCULATORMANAGER_H
