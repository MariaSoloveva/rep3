#include <cmath>
#include <iostream>

bool Check(std::string str)
{
    int countSign = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if ((!isdigit(str[i]) && !isdigit(str[i+1])) && !isalpha(str[i]))
        {
            return false;
        }
    }
    return true;
}
void breakArr(std::string str, int * sign, double * num, int * cs, int * cn)
{
    std::string allSign = "+-*/";
    for (int i = 0; i < str.size(); ++i)
    {
        double c = 0;
        int fl = 0;
        while (str[i] >= '0' && str[i] <= '9')
        {
            fl = 1;
            c = c * 10 + (str[i++] - '0');
        }
        if (fl)
            num[(*cn)++] = c;
        fl = allSign.find(str[i]);
        if (fl != -1)
            sign[(*cs)++] = fl;
    }
}

double changeValue(double a, double b, int sign) {
    double c = 0;
    switch (sign) {
        case 0:
            c = a + b;
            break;
        case 1:
            c = a - b;
            break;
        case 2:
            c = a * b;
            break;
        case 3:
            c = a / b;
            break;
    }
    return c;
}

int main()
{
    std::string expression;
    std::cout << "Enter expression: ";
    getline(std::cin, expression);
    expression += ' ';
    int sign[expression.size() / 2];
    double num[expression.size() / 2];
    int countSign = 0;
    int countNum = 0;
    breakArr(expression, sign, num, &countSign, &countNum);
    if (Check(expression)) {
        while (countNum > 1) {
            int numOper = 0;
            for (int i = 0; i < countSign; ++i)
                if (sign[i] > 1) {
                    numOper = i;
                    break;
                }
            num[numOper] = changeValue(num[numOper], num[numOper + 1], sign[numOper]);
            for (int i = numOper + 1; i < countNum; i++)
                num[i] = num[i + 1];
            for (int i = numOper; i < countSign; i++)
                sign[i] = sign[i + 1];
            countNum--;
            countSign--;
        }
        std::cout << "Result: " << num[0] << std::endl;
    } else {
        std::cout << "I don't understand" << std::endl;
    }
    return 0;
}
