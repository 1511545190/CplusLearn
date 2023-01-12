//
// Created by 刘日亮 on 2023/1/27.
//
#include <iostream>
#define N 8
using namespace std;
int queen_position[100];
void NQueen(int k){
    //在0~n-1 行 皇后已经摆好的情况下，摆第k行
    //及其后的皇后
    int i;
    if(k==N){
        for(i=0;i<N;i++)
            cout<< queen_position[i] + 1 <<" ";
        cout<<endl;
        return;
    }
    for(i = 0;i<N;i++){
        int j;
        for(j=0;j<k;j++){//逐个尝试第k个皇后的位置
            //和已经摆好的k个皇后的位置比较，看是否冲突
            if(queen_position[j] == i||
            abs(queen_position[j] - i) == abs(k - j)){
                break;//冲突
            }

        }
        if(j==k)
        {
            queen_position[k]=i;
            NQueen(k+1);
        }
    }
}
int main(){
    return 0;
}