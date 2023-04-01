//
// Created by 刘日亮 on 2023/3/18.
//
#include "leetcode.h"
/*
 * 最核心点是：在倒之前判断了是否输出栈为空
 */
class MyQueue {
private:
    stack<int> inStack, outStack;

    void in2out(){
        while(!inStack.empty()){
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
public:

    /* 若输出栈为空则将输入栈的全部数据依次弹出并压入输出栈
     * ，这样输出栈从栈顶往栈底的顺序就是队列从队首往队尾的顺序。
     * */
    MyQueue() {

    }

    void push(int x) {
        inStack.push(x);//压入输入栈
    }

    int pop() {
        //如果输出栈是空的那么，压入
        if(outStack.empty())/*Key*/
            in2out();
        int ans = outStack.top();outStack.pop();
        return ans;
    }

    int peek() {
        if(outStack.empty())
            in2out();
        return outStack.top();

    }

    bool empty() {
        return inStack.empty()&&outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */