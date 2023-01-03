//
// Created by 刘日亮 on 2022/12/31.
//
#include <iostream>
#include  <list>
#include <vector>
#include <stack>
using namespace  std;
int main(int argc, char* argv[])
{
    list<int> a;//链表a

    //添加
    a.push_back(11);
    a.push_back(22);
    a.push_back(33);
    //遍历
    for(auto i:a)
        cout<<i<<",";
    cout<<endl;
    //插入
    a.insert(a.begin(),666);


//    a.insert(a.begin()+1,666); 不可以,地址不连续

    list<int>::iterator it = a.begin();
    while(it!=a.end())
        cout<<&*it<<" "<<*it++<<",\n";
    cout<<endl;
    it=a.begin();
    a.remove(666);
    a.erase(a.begin());





    return 0;
}
