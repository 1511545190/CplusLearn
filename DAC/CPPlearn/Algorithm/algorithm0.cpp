#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
class A{
    public:
        int n;
    A(int i ):n(i){}
};
bool operator < (const A&a1, const A& a2)
{
    cout<<"< called"<<endl;
    if(a1.n==3 && a2.n ==7)  // 只有3 < 7 为 小于
        return true;
    return false;
}
int main()
{
    A aa[] = {3,5,7,2,1};
    //一开始假设3最小
    cout<< min_element(aa,aa+5)->n <<endl;
    cout<< max_element(aa,aa+5)->n <<endl;
    return 0;
}