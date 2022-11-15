#ifndef _MY_CLASS_
#define _MY_CLASS_

//头文件用于定义一个类
class library{
    public:
        int realtime_pupularity;
        bool open;
        void nameit(char[]);
        void showname();
        void showcapacity();
        void changecap();
        


    private:
    //变量是属于类的
        int capacity;
        char name[10];
};
#endif

//变量是可以重复声明的
extern int a;
extern int a;
extern int a;