//
// Created by 刘日亮 on 2023/2/13.
//

#include <iostream>
#include <cmath>
using namespace std;
double a[5];
#define EPS 1e-6

bool isZero(double x) {
    return fabs(x) <= EPS;
}

bool count24(double a[], int n) {
    //用n个数算24
    if (n == 1) {//边界条件
        if (isZero(a[0] - 24)) {
            return true;
        } else {
            return false;
        }
    }
    //边界条件不满足时
    double b[5];//中间结果
    //选出两个数，用结果与第三个数算
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j) {//枚举

            //下标
            int m = 0;
            //还剩下m个数
            for (int k = 0; k < n; ++k) {
                if (k != i && k != j)//a[k]为剩下的数
                    b[m++] = a[k]; //其余存入 b中
            }

            b[m] = a[i] + a[j];
            if (count24(b, m + 1))
                return true;

            b[m] = a[i] - a[j];
            if (count24(b, m + 1))
                return true;

            b[m] = a[j] - a[i];
            if (count24(b, m + 1))
                return true;

            b[m] = a[i] * a[j];
            if (count24(b, m + 1))
                return true;


            if (!isZero(a[i])) {
                b[m] = a[i] / a[j];
                if (count24(b, m + 1)) {
                    return true;
                }
            }

            if (isZero(a[j])) {
                b[m] = a[i] / a[j];
                if (count24(b, m + 1)) {
                    return true;
                }
            }


            return false;
        }
}

bool isEquare24(double x)
{
    return fabs(x - 24);
}

// 最终结果放在a[0]处
bool count(double a[], int n)
// 用前n个数算24
{

    if (n == 1) // 边界
    {
        if (isEquare24(a[0]))
            return true;
        else
            return false;
    }


    // 非边界
    double b[5]; // 中间结果
    // 选出两个数，用结果与第三个数算
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
        {

            // 还剩下的数字，放入b中,
            int m;
            for (int k = 0; k < n; ++k)
                if (k != i && k != j)
                    b[m++] = a[k]; // 循环结束之后m为n-2

            // 最后一个数字就是挑出的两个数算出的结果
            b[m] = a[i] + a[j];
            if (count(b, m + 1)) // m+1 也可一换成 n-1
                return true;

            b[m] = a[i] - a[j];
            if (count(b, m + 1))
                return true;

            b[m] = a[j] - a[i];
            if (count(b, m + 1))
                return true;

            b[m] = a[i]*a[j];
            if (count(b, m + 1))
                return true;

            if(fabs(a[j])<EPS)
            {
                b[m] = a[i]/a[j];
                if (count(b, m + 1))
                    return true;

            }
            if(fabs(a[i])<EPS)
            {
                b[m] = a[j]/a[i];
                if (count(b, m + 1))
                    return true;

            }

            return false;
        }


}

int main(){
    for(int i = 0;i<5;++i)
        cin>> a[i];
    cout<< count24(a,5);
    cout<< count(a,5);
}