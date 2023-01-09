//
// Created by 刘日亮 on 2023/1/8.
//

#include <stdio.h>
int main(){
    int num = 1,num2 =2;
    [=]()->void {
        //=
        //&
        printf("Hello World!\n");
        printf("n:%d",num);
        return;
    }();


    //lambda 匿名函数 指针指向
    int (*pFun)(int&) =[](int& n)->int {
        n = 250;
        return 0;
    };
    pFun(num);
    printf("\n%d",num);
     ;
}