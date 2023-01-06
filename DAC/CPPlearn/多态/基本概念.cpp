//
// Created by 刘日亮 on 2023/1/4.
//

//在类中，virtual
// （构造和静态不能)

//同名虚函数指哪打哪
//非虚函数同名 指针调用 基类
#include <iostream>

using namespace std;

class A {
public:
    virtual void Print() {
        cout << "A::Print\n";
    }

    void no_virual_print() {
        cout << "A::no_virtual_print\n";
    }
};

class B : public A {
public:
    virtual void Print() {
        cout << "B::Print\n";
    }

    void no_virual_print() {
        cout << "B::no_virtual_print\n";
    }
};

class C : public B {
public:
    virtual void Print() {
        cout << "C::Print\n";
    }

    void no_virual_print() {
        cout << "C::no_virtual_print\n";
    }
};

class D : public C {
public:
    virtual void Print() {
        cout << "D::Print\n";
    }

    void no_virual_print() {
        cout << "D::no_virtual_print\n";
    }

};

int main() {
    //如果没有多态，那么指向的是A的函数
    A *p;
    A a;
    B b;
    C c;


    p = &a;
    p->Print();
    p->no_virual_print();

    p = &b;
    p->Print();
    p->no_virual_print();

    A &invoke_p = c;
    invoke_p.Print();
    invoke_p.no_virual_print();


    return 0;
}

