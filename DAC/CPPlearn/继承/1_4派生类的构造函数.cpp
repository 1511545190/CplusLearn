//
// Created by 刘日亮 on 2023/1/4.
//
#include <iostream>
using namespace std;
class Bug{
private:
    int nLegs;
    int nColor;
public:
    int nType;
    Bug(int Legs, int color);
    void PrintBug(){};
    ~Bug();
};
Bug::Bug(int Legs, int color): nLegs(Legs), nColor(color){
    cout<<"Bug constructed!"<<endl;
}
Bug::~Bug(){
    cout<<"Bug distructed~"<<endl;
}

class Skill{
public:
    Skill(int n){cout<<"Sikll!"<<endl;}
};


class FlyBug: public Bug{
    int nWings;
public:
    Skill sk1,sk2;
    FlyBug(int Legs, int color, int nWings );
    ~FlyBug();
};
/*初始化列表初始化派生类构造函数*///成员对象也要初始化
FlyBug::FlyBug(int Legs, int color, int nWings): Bug(Legs,color), sk1(color), sk2(color){
    this->nWings =nWings;
    cout<<"Fly Bugs constructed!"<<endl;
}
FlyBug::~FlyBug(){
    cout<<"Fly Bugs distructed~"<<endl;
}

int main()
{
    //Bug bug(4,0);
    //bug.nType = 2;
    FlyBug flyBug(4,0,2);

    flyBug.nType  = 3;

    return 0;
}
