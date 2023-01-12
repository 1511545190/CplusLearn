//
// Created by 刘日亮 on 2023/1/11.
//

#include <iostream>
using namespace std;
template <class T,int size>
class CArray{
private:
    T array[size];
public:
    void Print()
    {
        for(int i = 0;i<size;++i)
        {
            cout<<array[i]<<endl;
        }
    }


};
//两个属于不同的类
CArray<int,10> Array10;
CArray<int,40> Array40;

