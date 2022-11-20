#include "Myclass.h"
#include <stdio.h>     //实现类的功能所需要用的库，只在此文件中使用

library::library():capacity(1), name("JJJ"), realtime_pupularity(1){
    printf("default function\n-----\n");

}


void library::showcapacity()
{
    printf("capacity= %d\n",capacity);
    //name 在类中声明了，所以可以直接用
}
void library::showname()
{
    printf("name :%s\n",this->name);
}
void library::changecap(int capacity)
{
    open = true;
    this->capacity =capacity;

}

library::~library()
{
    printf("----\n~ over\n");
}
void library::nameit(char nam[])
{
    for(int i =0;i<10;i++)
    {
        this->name[i]=nam[i];
    }
    
}

