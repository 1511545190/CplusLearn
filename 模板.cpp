//
// Created by 刘日亮 on 2023/1/11.
//
#include <iostream>
using namespace std;
template <class T1, class  T2>
class Pair{
public:
    T1 key;         //关键字
    T2 value;       //值
    Pair(T1 k, T2 v):key(k),value(v){};
    //overload                              //函数返回值位const
    bool operator < (const Pair<T1,T2> & p) const;
    const bool operator > (const Pair<T1,T2> & p);
};

template<class T1, class T2>
const bool Pair<T1, T2>::operator>(const Pair<T1, T2> &p) {
    return key > p.key;
}

template<class T1,class T2>
//pair<t1,t2> 类名
bool Pair<T1,T2>::operator < (const Pair<T1,T2> & p) const {
    //成员函数 operator <

    return key < p.key;

}


int main(){
    Pair<std::string ,int> student("Tom",19);
    cout<< student.key<<" "<<student.value<<endl;
    Pair<std::string ,int> student2("Tom",19);
    int a = student > student2;
    cout<< a<<endl;
    a = student < student2;
    cout<< a<<endl;
    return  0;
}