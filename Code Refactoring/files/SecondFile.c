#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "FirstHeader.h"

int is_digit(char* numb)
{
    int step = 0;
    while (numb[step])
        if (numb[step] < '0' || numb[step] > '9') {
            if (numb[step] == '.' || numb[step] == '!') {
                step++;
                continue;
            }
            return 0;
        }
        else step++;
    return 1;
}

double findConst(char* numb)
{
    if (!strcmp(numb, "PI")) return 3.1415926535;
    if (!strcmp(numb, "e")) return 2.7182818284;
    return 0;
}

double findFunc(char* numb, char* expression, int step, char** data)
{
	int func = 0;
    double digit = 0;

    if (!strcmp(numb, "sin"))
        func = 1;
    if (!strcmp(numb, "cos"))
        func = 2;
    if (!strcmp(numb, "tg"))
        func = 3;
    if (!strcmp(numb, "ctg"))
        func = 4;
    if (!strcmp(numb, "log"))
        func = 5;
    if (!strcmp(numb, "ln"))
        func = 6;
    if (!strcmp(numb, "abs"))
        func = 7;

    if (func) {
        return digit = calcFunction(expression, step, func, data);
    }
    else return 0;
}

makeExpression(char* expression, char** data, int row, int col)
{
    int step = 0;
    while (data[row][col]) {
        expression[step++] = data[row][col++];
    }
}

double findVar(char* numb, char** data)
{
    int row = 1, col = 0;
    while (data[row][col] && data[row][col] != ' ') {
        if (numb[col] != data[row][col]) {
            row++;
            col = 0;
            continue;
        }
        else
        {
            col++;
            continue;
        }
    }
    char expression[size] = { 0 };
    makeExpression(expression, data, row, col + 3);
    double digit = distributor(expression, data);
    return digit;
}


addSymb(char* numb, char symb)
{
    int step = 0;
    while (numb[step++])
    {
    }
    numb[step - 1] = symb;
}

double parse(char* numb)
{
    double digit = 0;
    if (numb[0] == '!') numb[0] = '-';
    sscanf(numb, "%lf", &digit);
    return digit;
}

int findNextStep(char* expression, int step)
{
    int point = step + 1, hooks = 1;
    while (hooks) {
        if (expression[point] == ')') hooks--;
        if (expression[point] == '(') hooks++;
        point++;
    }
    return point;
}

double distributor(char* expression, char** data)
{
    double stack[size] = { 0 };
    double op_stack[size] = { 0 };          //стек операторов
    int point = 0, op_point = 0;
    int step = 0;

    char numb[size] = { 0 };

    while (expression[step]) {
        char symb = expression[step];
        if (!is_operator(symb)) {           //если не оператор, то продолжить
            addSymb(numb, symb);
            step++;
            continue;
        }

        if (numb[0]) {
            double digit = 0;

            if (is_digit(numb)) digit = parse(numb);
            else {
                digit = findConst(numb);
                if (digit == 0) {
                    digit = findFunc(numb, expression, step, data);
                    if (digit) {
                        step = findNextStep(expression, step);
                        point = push(stack, point, digit);
                        memset(numb, '\0', size);
                        continue;
                    }
                    else {
                        digit = findVar(numb, data);
                    }
                }
            }
            point = push(stack, point, digit);
        }
       
        while(prio(symb) >= prio(top(op_stack, op_point)) && top(op_stack, op_point) != '(') {
            int operator = top(op_stack, op_point);
            op_point = pop(op_stack, op_point);

            if (operator == '|') {
                double a = top(stack, point);
                point = pop(stack, point);

                point = push(stack, point, calculate(a, 0, operator));
            }
            else {
                double b = top(stack, point);
                point = pop(stack, point);
                double a = top(stack, point);
                point = pop(stack, point);

                point = push(stack, point, calculate(a, b, operator));
            }
        }

        if (symb == ')' && top(op_stack, op_point) == '(') {
            op_point = pop(op_stack, op_point);
        }
        else op_point = push(op_stack, op_point, symb);
        

        memset(numb, '\0', size);
        step++;
    }

    if (numb[0]) {
        double digit = 0;

        if (is_digit(numb)) digit = parse(numb);
        else {
            digit = findConst(numb);
            if (digit == 0) {
                digit = findVar(numb, data);
            }
        }
        point = push(stack, point, digit);
    }

    while (!is_empty(op_stack, op_point))
    {
        int operator = top(op_stack, op_point);
        op_point = pop(op_stack, op_point);

        if (operator == '|') {
            double a = top(stack, point);
            point = pop(stack, point);

            point = push(stack, point, calculate(a, 0, operator));
        }
        else {
            double b = top(stack, point);
            point = pop(stack, point);
            double a = top(stack, point);
            point = pop(stack, point);

            point = push(stack, point, calculate(a, b, operator));
        }
    }
    return top(stack, point);
}