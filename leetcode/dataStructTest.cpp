//
// Created by 刘日亮 on 2023/3/19.
//
#include "leetcode.h"
int main(){
    stack<int> stack1;
    stack1.push(1);
    stack1.top();
    stack1.emplace(1);
    stack1.emplace(3);
    stack1.emplace(4);
    stack<int> stack2;
//    交换两个stack中的内容
    stack1.swap(stack2);

    return 0;



}