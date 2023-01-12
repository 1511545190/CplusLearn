//
// Created by 刘日亮 on 2023/1/3.
// 前置为一元运算符，重载时只需要一个参数
//++a前置返回引用（cpp中）
// 后置为二元运算符，重在时需要两个参数
//a++后置
#include <iostream>

using namespace std;

class CDemo {
    int value;
public:
    CDemo(int a = 0) : value(a) {}

    //重载
    operator int() { return value; }

    CDemo &operator++();//前置形式
    CDemo operator++(int);//后置形式
    friend CDemo &operator--(CDemo &);

    friend CDemo operator--(CDemo &, int);

};

//前置形式
CDemo &CDemo::operator++() {
    ++value;
    //返回引用,
    // 返回对象没有问题
    return *this;
}

//后置++
CDemo CDemo::operator++(int k) {
    //后置返回++之前的值
    CDemo tmp(*this);//拷贝
    value++;
    return tmp;
}


//前置返回引用，才能被修改
//全局必须传引用，才能修改
CDemo &operator--(CDemo &d) {
    d.value--;
    return d;
}

//后置直接返回对象
CDemo operator--(CDemo &d, int k) {
    CDemo temp(d);
    d.value--;
    return temp;
}

int main() {
    CDemo d(5);
    cout
            << d++ << ","  //等价于 d.operator++(0)
            << d << ","  //可以重载强制类型转换，或者<<
            << ++d << "," //d.operator++()
            << d << ","
            << d-- << ","     //d.operator--(0)
            << d << ","
            << --d << ","    //d.operator--()
            << d << ","
            << endl;

    return 0;
}
//注意
/*
 * () [] -> 必须声明为成员函数
 * 。、。* :: 不能被重载
 */
