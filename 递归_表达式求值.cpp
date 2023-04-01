//
// Created by 刘日亮 on 2023/2/13.
//

//表达式求值
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cmath>

using namespace std;

int factor_value();

int term_value();

int expression_value();

int main() {
    cout << expression_value() << endl;
    return 0;
}

int expression_value() {
    int result = term_value();
    bool more = true;
    while (more) {
        char op = cin.peek();
        if (op == '+' || op == '-') {
            cin.get();
            int value = term_value();
            if (op == '+') {
                result += value;
            } else {
                result -= value;
            }
        } else more = false;
    }
    return result;
}

int term_value() {
    int result = factor_value();
    char op = cin.peek();
    bool more = true;
    while (more) {
        if (op == '*' || op == '/') {
            cin.get();
            int value = factor_value();
            if (op == '*') {
                result *= value;
            } else {
                result /= value;
            }
        } else
            more = false;

    }
}

int factor() {
    int result = 0;
    int op = cin.peek();
    if (op == '(') {
        cin.get();
        result = expression_value();
        cin.get();
    } else {
        while (isdigit(op)) {
            result += result * 10 + op - '0';
            cin.get();
            op = cin.peek();
        }
    }
    return result;
}



