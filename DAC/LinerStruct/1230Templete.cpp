/* 
模板与泛型
 */
#include <iostream>
#include <vector>
using namespace std;

//语法：T表示投个类型，此时这里不是类，是一个模板
template<class T>
class Table{
public:
    T a;
    T b;
};

int main()
{
    //用int 来填充了模板
    Table<int> t;
    t.a = 3;
    t.b = 2;
    Table<double> tt;
    tt.a = 2.3;
    tt.b = 3.5;

    

    return 0;
}