#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
void setbit(int& data, int index, int value){
    if(value)//设置1
        data |= 1<<index;
    else
        data &= ~(1<<index);
}
int getBit(int data, int index){
    return 1&(data>>index);
}
int FlipBit(int &data, int index){
    if(getBit(data,index)){
        setbit(data,index,0);
    }else{
        setbit(data,index,1);
    }
}
int main()
{
    int data;
    cin >> data;
    for(int i = 0;i<20;++i)
        cout<< getBit(data,i);
    cout<<endl;
    int check = data;
    int step =0;
    for(int i = 0 ;i < 20;++i)//列举按了多少个按钮
    {
        if(i==0)
        {FlipBit(data,0);FlipBit(data,1);}
        else if(i==20-1)
        {FlipBit(data,i-1);FlipBit(data,i);}
        else{
        FlipBit(data,i-1);FlipBit(data,i+1);FlipBit(data,i);}

        step++;
        //check
        if(data == check)   return step;
    }
    return 0;
}