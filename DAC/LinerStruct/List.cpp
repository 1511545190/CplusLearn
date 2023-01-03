//
// Created by 刘日亮 on 2022/12/31.
//
#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;


//重载使用
ostream &operator<<(ostream &out, const vector<int> &v) {
    for(auto x:v)
        cout<<x<<",";
    cout<<endl;
    return out;
}

int main(int argc, char* argv[]){
    vector<int> v;
    //插入
    v.push_back(11);
    v.push_back(22);
    v.push_back(33);//会参数拷贝构造
    v.emplace_back(44);//在向量内部直接钩爪
    cout<<v<<endl;

    //插入
    v.insert(v.begin(),0);
    v.insert(v.begin()+1,100);
    cout<<v<<endl;

    //删除
    v.erase(v.end()-1);
    cout<<v<<endl;

    //print
    for(auto i:v)
        cout<<i<<",";
    cout<<endl;

    //iterator
    vector<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
        cout<<*it<<",";//类指针使用
    cout<<endl;
    //重载使用
    cout<<v;



    return 0;
}
