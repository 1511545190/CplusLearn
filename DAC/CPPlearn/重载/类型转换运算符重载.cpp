//
// Created by 刘日亮 on 2023/1/3.
//类型转化运算符重载
#include <iostream>
using namespace std;
class Complex
{
    double real,imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){};
    operator double (){return real;}
    //重载强制类型转换运算符
    //返回值类型为double
    //在任何需要x的地方


};
int main()
{
    Complex c(1.2,3.4);
    //显式转换
    cout<< (double)c<<endl;//输出1.2
    //自动转换
    double n = 2+ c;//等价于2 + c.operator double()
    cout<< n;

    return 0;
}
