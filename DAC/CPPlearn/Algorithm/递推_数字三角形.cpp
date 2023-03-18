//
// Created by 刘日亮 on 2023/2/19.
//

#include <iostream>
using namespace std;
#define N 100

int input[N+1][N+1];

int main(){
    int n;
    cout << "before you input data, you should input the number of plies"<<endl;
    cin >> n;
    //输入
    for(int i =0;i<n;++i)
    {
        for(int j = 0;j<=i;++j)
        cin>>input[i][j];
    }

    //处理
    for(int i =n-1;i>0;--i)//对第0行就不用这样操作了
    {
        for(int j = 0;j<=i;++j)//从底部递推，从每对中找到最大的
        {
            if (input[i][j] < input[i][j + 1]){
                input[i-1][j-1] += input[i][j+1];
            }else{
                input[i-1][j-1] += input[i][j];
            }
        }

    }
    cout<< endl<<input[0][0]<<endl;


    return 0;
}


