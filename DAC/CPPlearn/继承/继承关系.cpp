//
// Created by 刘日亮 on 2023/1/3.
//继承全部成员和变量，只是不能访问private变量（但继承了)
// 基类，派生类（可以独立使用)
//修改(覆盖)、扩充：添加新的成员函数

/* a 派生自 A
 * class a:public A
 */
#include <iostream>
using namespace std;
//Basis
class Student{
protected:
    //派生类——中———也可以访问
    //main中不能直接访问

private:
    string Name;
    int Age;
public:
    bool Prize();
    void SetName(const string& name){Name=name;}
    //...
    Student(string& name):Name(name){}
};

class UnderGraduate:public Student{
private:
    int Department;
public:
    bool Prize() {
                                            //可以调用基类的函数，再覆盖
        cout << "He/She was Prized : " << Student::Prize() << endl;

    }
    bool IsAssistant();
};

int main()
{

    return 0;
}


