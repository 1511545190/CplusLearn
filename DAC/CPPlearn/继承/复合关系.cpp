//

// Created by 刘日亮 on 2023/1/3.
//
//主人和狗的关系
class CMaster;
class CDog{//”知道关系“ 用指针
    CMaster* pm;
};
class CMaster{
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
