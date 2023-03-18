//
// Created by 刘日亮 on 2023/2/19.
//

#include <iostream>
#include <algorithm>

#include <cstring>
using namespace std;
//用数组来存储结果，若算过了，那就不算了
#define N 3
int result[N][N];
int Data[100][100];
int max_sum(int i,int j){
    if(i == 3)
        return result[i][j] = Data[i][j];//注意每个值都要存

    if(result[i][j])//有数据直接返回数据
        return result[i][j];

    else
    {
        int value = Data[i][j] + max(max_sum(i+1,j), max_sum(i+1,j+1));
        result[i][j] = value;
        return value;

    }

}
int main()
{
    memset(result,0,sizeof(result)*100);

    for(int i = 0;i<3;++i)
    {
        for(int j=0;j<=i;++j)
            cin >> Data[i][j];
    }
    cout<<endl<< max_sum(0,0);



    return 0;
}