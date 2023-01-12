//
// Created by 刘日亮 on 2023/1/14.
//

#include <iostream>
#include <string>
#include <cstring>
#include <memory>
using namespace std;

char oriLight[5];
char Light[5];//变化
char Result[5];//开关方案

int GetBit(char c, int i)
{
    return (c>>i) &1;
}
//设置位
void SetBit(char &c, int i , int v)
{
    if(v){
        c|=(1<<i);
    }
    else{
        c &= ~(1 << i);
    }

}

//反转
void FlipBit(char &c, int i)
{
    //^反转, ^1 反转 ^0不变
    c^=(1<<i);
}
//输出结果  cases result
void OutPutRusult(int t, char result[]){
    cout<<"PUZZLE #"<<t<<endl;
    //列
    for(int i = 0;i<5;++i)
    {
        for(int j = 0;j<6;++j)
        {
            cout<< GetBit(result[i],j);
            if(j<5)
                cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int T;
    cin >>T;//读入测试数据的组数
    for(int t =1;t<=T;++t)
    {
        for(int i =0;i<5;++i)
            //处理灯的数据
            for(int j = 0;j<6;++j)//第j个bit
            {
                int s;
                cin >>s;//第i行第j列的状态
                SetBit(oriLight[i],j,s);
            }
        }
    //枚举第一行的所有状态，0---->2的64次方-1
    for(int n = 0;n<64;++n) {

        int switchs = n;
        memcpy(Light,oriLight,sizeof(oriLight));


        for(int i =0;i<5;++i){
            Result[i] = switchs;
            for(int j=0;j<6;j++){
                if(j>0)
                    FlipBit(Light[i],j-1);
                FlipBit(Light[i],j);
                if(j<5)
                    FlipBit(Light[i],j+1);
            }
            if(i<4){//影响下一行
                Light[i+1] ^= switchs;

            }
            switchs = Light[i];
        }

        if(Light[4]==0){
            OutPutRusult(n,Result);
            break;
        }

    }
}

