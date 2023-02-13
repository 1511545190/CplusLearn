//
// Created by 刘日亮 on 2023/2/13.
//

#include <iostream>
#include <cmath>
using namespace std;
double a[5];
#define EPS 1e-6
bool isZero(double x){
    return fabs(x ) <= EPS;
}
bool count24( double a[], int n)
{
    //用n个数算24
    if(n == 1){//边界条件
        if(isZero(a[0] - 24)){
            return true;
        }else{
            return false;
        }
    }
    //边界条件不满足时
    double b[5];//中间结果
    //选出两个数，用结果与第三个数算
    for(int i = 0;i< n-1;++i)
        for(int j = i+1;j< n;++j){//枚举

            int m = 0;
            //还剩下m个数
            for(int k = 0;k< n;++k){
                if(k != i&&k!= j)//a[k]为剩下的数
                    b[m++] = a[k]; //其余存入 b中
            }

            b[m] = a[i]+a[j];
            if(count24(b,m+1));
                return true;
            b[m] = a[i]-a[j];
            if(count24(b,m+1));
            return true;
            b[m] = a[j]-a[i];
            if(count24(b,m+1));
            return true;
            b[m] = a[i]*a[j];
            if(count24(b,m+1));
            b[m] = a[i]/a[j];
            if(count24(b,m+1));
            return true;

            b[m] = a[i]/a[j];
            if(count24(b,m+1));
            return true;
            return true;




        }
}