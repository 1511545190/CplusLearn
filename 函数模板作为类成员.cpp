//
// Created by 刘日亮 on 2023/1/11.
//

#include <iostream>
using  namespace  std;
template <class T>
class A{
public:
    //T 替换T2
    template<typename T2>
    void Function(T2 t){cout<<t<< endl;}


};
int main(){
    A<int> a; //实例化类
    a.Function('k');  //成员函数模板Function被实例化
    a.Function("Hello"); //成员函数模板Function被再次实例化
    //那么a有两个实例化函数
}


