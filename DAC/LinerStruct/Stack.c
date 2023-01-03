//
// Created by 刘日亮 on 2022/12/31.
//
#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int* data;  //数据动态存储
    int capacity;//容量
    int top;     //栈顶元素
};

void init(struct Stack* st,int capacity){
    st->data = (int*) malloc(capacity*sizeof (int));
    st->capacity = capacity;
    st->top =0;//top 初始化为顶上顶
}
int isFull(const struct Stack* st)
{
    if(st->top==st->capacity){
        return 1;
    }
    return 0;
}
int push(struct Stack* st,int value){
   if(!isFull(st)) {
       st->data[st->top] = value;
       st->top++;
       return 1;
   }
    return 0;
}
int isEmpty(struct Stack* st){
    if(st->top==0) return 1;
    return 0;
}
int pop(struct Stack* st,int *x){

    if(!isEmpty(st)){
        st->top--;
       *x = st->data[st->top];
        return 1;
    }
    return 0;
}

int top(const struct  Stack* st){
   if(isEmpty(st))return 0;
    return st->data[st->top-1];
    return 1;
}
int destory(struct Stack* st){
    free(st);
    return 0;
}

int isIn(struct Stack* st, int x){

}

int main()
{
    struct Stack st;



    destory(&st);
    return 0;
}