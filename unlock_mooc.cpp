#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int GetBit(int c, int i){return (c>>i)&1;}
void SetBit(int&c, int i,int v){
    if(v) c|=(1<<i);
    else c&= ~(1<<i);
}
void FlipBit(int&c, int i){c^=(1<<i);}
int main()
{
    string LockLine;
    int OriLock = 0;
    int DesLock = 0;
    int CurLock = 0;

    //
    getline(cin,LockLine);
    int len = LockLine.size();
    for(int i=0;i<len;++i) SetBit(OriLock,i,LockLine[i]-'0');

    getline(cin, LockLine);
    for(int i = 0;i<len;++i) SetBit(DesLock,i,LockLine[i]-'0');

    int mintimes = len;
    for(int i = 0;i<2;++i){//第一个按钮只有0/1,整个系统只与初始值有关
        CurLock = OriLock;
        int switchs = i;
        int times = 0;
        for(int j = 0; j< len;++j)
        {
            //依次对每个按钮进行处理
            if(switchs)
            {
                times++;
                if(j>0) FlipBit(CurLock,j-1);
                if(j<len-1) FlipBit(CurLock,j+1);
                FlipBit(CurLock,j);

            }
            if(j<len-1)//当前按钮与目标状态一致，则 swichs = 0，否则 未1
                switchs = GetBit(CurLock,j) ^ GetBit(DesLock,j);
        }
        if(CurLock == DesLock)
            mintimes = min(mintimes,times);
    }
    if(mintimes == len)
        cout<<"impossible"<<endl;
    else   
        cout<<mintimes<<endl;
    return 0;
}