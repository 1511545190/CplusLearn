//
// Created by 刘日亮 on 2023/1/9.
//

#include <iostream>
#include <vector>
#define N 21252
using namespace std;
int main()
{
    // 23 28 33
    int p ,e,i,d,count = 0;
    //输入数据并且，设置退出条件
    while(cin>>p>>e>>i>>d && p!=-1){
        ++count;
        int k; //高峰出现在第几天
        /*tip:for循环入口条件与循环变量相关，那么当循环结束时，循环变量为入口条件对于0值*/
        for(k=d+1;(k-p)%33;k++);//先将k设置成第一个智力高峰
        //接着在I高峰的范围内寻找情商高峰
        for(;(k-e)%28;k+=33);
        

        //接着在体力高峰中寻找
        //跳步为前面两个的最小公倍数
        for(;(k-p)%23;k+=(28*33));
        cout<<"Case: "<<count<<"the next thriple peak in "<<k-d<<endl;

    }
}
