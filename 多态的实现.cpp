//
// Created by 刘日亮 on 2023/1/7.
//
/*
 * 多态使用虚函数表来实现，程序运行时动态联编
 * 每一个类都有虚函数的地址（表内存放虚函数的指针（对于64位来说有8个字节））
 *
 *
 * */
#include <iostream>
using namespace std;
class A{
public:
    virtual void Print(){
        std::cout<<"A::Print\n";
    }
};
class B:public A{
public:
    virtual void Print(){
        std::cout<<"B::Print\n";
    }
};
int main()
{
    A a;
    A *p = new B(); //基类指针
    p->Print(); //调用B 的 print
    // 虚函数地址覆盖
    // 8个字节 long long
    //cout<< sizeof(long long)<<endl;

    long long *  p1 = (long long*)&a;
    long long * p2 = (long long*)p;
    *p2 = *p1; //父类赋给子类

    p->Print();
    return 0;
}