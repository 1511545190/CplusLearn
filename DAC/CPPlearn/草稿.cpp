//
// Created by 刘日亮 on 2023/1/17.
//

#include <iostream>
using namespace std;



/* 打开位，关闭位练习
 *  查看位练习
 * */
//打开位，position 是第几位，sigature是 0/1
int BinarySwitch(int &input,int position, int signature){
    int flag = 1;
    int a;
    //打开
    if(signature){
        a = 1 << position;
        input |= a;
    }else{
        a = 1 << position;
        //关闭位
        input &= ~a;
    }
    //position

    return flag;
}

int OutputBinary(int input,int position){
    return (input >> position) & 1;
}

int OutputBinary2(int input,int position){
    int output =0;

    output = input&(~(0<<position));
    output>>=position;

    return output;
}


int main()
{
    cout<<sizeof(int)<<endl;
    //假定一个数字，以二进制的形式输出其各位
    int input, position, sign;
    cout<< "Input the number that you want to operate "
    << "then input the position you'd like to set "
    << "and what binary you want to set"<<endl;
    cin>>input;
    cout<< "Set "<<input<<endl;
    while(cin>>position>>sign)
    {
        cout<<"Set "<<position<<" position to"<<sign<<endl;
        BinarySwitch(input,position,sign);
        for(int i  = 31;i>=0;i--)
        {
            cout<<OutputBinary(input,i);
        }
        cout<<endl;
    }


    return 0;
}
