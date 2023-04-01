//
// Created by 刘日亮 on 2023/1/7.
//
#include <iostream>
using namespace std;

void test1() {
    cout<<"1: \n";
    class son {
    public:
        ~son() { cout << "bye From son\n"; }
    };
    class grandson : public son {
    public:
        ~grandson() { cout << "bye From GrandSon\n"; }
    };

    son *pson = new grandson();
    delete pson;//只执行基类的析构函数
    cout<<endl;
}
//虚析构函数
void test2(){
    cout<<"2: \n";
    class son {
    public:
        virtual ~son() { cout << "bye From son\n"; }
    };
    class grandson : public son {
    public:
        virtual ~grandson() { cout << "bye From GrandSon\n"; }
    };

    son *pson = new grandson();
    delete pson;//从子到父执行虚构函数
    cout<<endl;

}
//抽象类：含有纯虚函数的类不能够直接声明实例，只能用作父类
// 只有当所有纯虚函数都实现了才能够声明实例
void test3(){
    cout<<"3:\n";
    class A{
    public:
        virtual void f() = 0;//纯虚函数
        void g(){
            this->f();  //可以使用，相当于多态（基类指针）
            //f();  //由于只有被实现后，才能够声明实例，所以对子类来说有意义
        }
        A(){
            //f(); 错误 //构造函数内f() 还未实现
        }
    };
    class B:public A{
    public:
        void f(){cout<<"B:f()\n";}//自动virtual
    };

    B b;
    b.g();

}
int main(){

    test1();
    test2();
    test3();

    char name[10] = "nihaoyaya";
    char *p  = &name[1];
    cout<<p[-1];


    return  0;
}
