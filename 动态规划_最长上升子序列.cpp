//
// Created by 刘日亮 on 2023/2/19.
//
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 101;
int a[MAXN];
int maxLen[MAXN];
int main(){
    int N;
    cout << "please input the size of sequence first"<<endl;
    cin >> N;
    for(int i =1;i<=N;++i)
    {
        cin >> a[i]; maxLen[i] =1;
    }

    for(int i = 2;i<=N;++i)
    {//每次求以第i个数为终点的最长上升子序列的长度
        for(int j = 1;j<i;++j)
        {//查看以第j个数为终点的最长上升子序列
            if(a[i]>a[j])//找最大的+1
                maxLen[i] = max(maxLen[i],maxLen[j] +1);//maxLen[i] 默认为1
            //否则默认为1
        }
    }
    //algorithm中找最大值的算法
    cout<< *max_element(maxLen+1,maxLen+N+1);

    return 0;

}
