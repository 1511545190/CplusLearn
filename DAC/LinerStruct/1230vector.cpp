#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Stu{
    public:
    //声明友元函数，便于访问private
    friend ostream& operator << (ostream& o, const Stu&s);
    //构造函数
    Stu(string id,int score);
    private:
    string id;
    int score;
};
//返回值             <<前的对象    <<后的对象
ostream &operator<<(ostream &o, const Stu &s)
{
    //o 代表cout
    o<< "(" << s.id <<","<< s.score<<")";
    //为了后续能够连续输出，返回cout的引用
    return o;
}

Stu::Stu(string id,int score){
    this->id = id;
    this->score = score;
}
int main()
{
    //向量：实际上是一个模板

    Stu zs("s001",95);
    cout   << zs   <<endl;    //需要重载<<运算符
    vector<Stu> vect;
    vect.emplace_back("s001",95);  //调用构造函数初始化
    vect.emplace_back("s002",95);
    for(auto x:vect)
        cout<<x<<endl;

    

    

    return 0;
}

