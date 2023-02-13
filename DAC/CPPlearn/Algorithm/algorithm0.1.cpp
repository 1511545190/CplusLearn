#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
using namespace std;
class CLessThen9{
    public:
        bool operator()(int n){return n < 9;}
};
void outputSquare(int value){ cout<< pow(value,2)<<endl;}
int calculateCube(int value){ return pow(value,3);}
int main()
{
    const int SIZE = 10;
    int a1[] = {1,2,3,4,5,6,7,8,9,10,};
    int a2[] = {100,2,8,32,55,44,33,1,3,5,};
    vector<int> v(a1,a1+SIZE);
    ostream_iterator<int> output(cout, " ");
    random_shuffle(v.begin(),v.end());
    cout<<endl<<"1)";
    //
    copy(v.begin(),v.end(),output);
    copy(a2,a2+SIZE,v.begin());
    cout<<endl<<"2)";
    cout<<count(v.begin(),v.end(),8);
    cout<<endl<<"3)";
    cout<<count_if(v.begin(),v.end(),CLessThen9());
    cout<<endl<<"7)";
    cout<<*(min_element(v.begin(),v.end()));
    cout<<*(max_element(v.begin(),v.end()));
    cout<<endl<<"6)";
    cout<<accumulate(v.begin(),v.end(),0);
    cout<<endl<<"7)";
    //对每一个都进行outPutSuquare操作
    for_each(v.begin(),v.end(),outputSquare);
    vector<int> cubes(SIZE);
    //操作后转移
    transform(a1,a1+SIZE,cubes.begin(),calculateCube);
    cout<<endl<<"8)";
    copy(cubes.begin(),cubes.end(),output);
    return 0;
}