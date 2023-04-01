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
    //派生类成员函数——中———也可以访问
    //main中不能直接访问
    int prote;

private://派生类不可以继承，不能访问
    string Name;
    int Age;

public:
    bool Prize();
    void SetName(const string& name){Name=name;}
    //...
    Student(const char *name, int proted, int age): Name(name), Age(age), prote(proted){}
};

class UnderGraduate:public Student{
private:
    //char prote; 可以重写
    int Department;
public:
    UnderGraduate(const char *name, int age, int proted, int Dep);
    //直接重写
    bool Prize() {
                                            //可以调用基类的函数，再覆盖
        cout << "He/She was Prized : " << Student::Prize() << endl;
        cout<< "Student protected: "<<prote<<endl;
        //cout <<" Student private: " <<Student::Name<<endl;
        /*私有不可以访问*/
        //prote; char

    }
    bool IsAssistant();
};
//初始化列表 初始基类的私有成员 以及自身的成员变量
//初始化顺序：基类，成员对象，自身 ，析构顺序与初始化顺序相反
UnderGraduate::UnderGraduate(const char *name, int age, int proted, int Dep): Student(name, proted, age), Department(Dep) {
}

int main()
{
    int age = 12;
    int prote = 0;
    int de = 1;
    Student stu("name",prote,age);
    UnderGraduate ustu("name2",age,prote,de);
    return 0;
}


