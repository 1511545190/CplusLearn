//
// Created by 刘日亮 on 2023/1/1.
//
#include <iostream>
#include <stack>
#include <set>
#include <unordered_set>  //，count从后往前数


using namespace std;
#define N 20

////手写栈
//template<class T>
//class ST {
//private:
//    T *data;
//public:
//
//
//};


int main() {
    unordered_set<char> seen;
    string s = "abddba";
    for(auto i:s){
        if(seen.count(i)){
            cout<<i;
        }
        seen.insert(i);
    }
    return 0;
}
