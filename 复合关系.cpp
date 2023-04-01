//

// Created by 刘日亮 on 2023/1/3.
//
//主人和狗的关系
class CMaster;
class CDog{//”知道关系“ 用指针
public:
    CMaster* pm;
};
class CMaster{
public:
    char name[10];
    //主人有10条狗
    CDog * dogs[10];
};

class Point{
    double x,y;
    //设置了友元，Circle便可以访问x,y
    friend class Circle;
};

class Circle{
    double r;
    Point center;//圆中有圆心
};

int main(){
    CMaster host;
    CDog dog[10];

    host.dogs[0] = &dog[0];
    host.dogs[1] = &dog[1];
    host.dogs[2] = &dog[2];
    host.dogs[3] = &dog[3];
    host.dogs[4] = &dog[4];
    host.dogs[5] = &dog[5];
    host.dogs[6] = &dog[6];
    host.dogs[7] = &dog[7];

    dog[0].pm->name;


    return 0;
}