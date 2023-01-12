//
// Created by 刘日亮 on 2023/1/27.
//
#include <iostream>
using namespace std;
//Hanoi
void Hanoi(int n, char src, char mid, char dest){
   //将n-1个放到中间，将最后一个放到dest，将n-1放到dest
   if(n == 1){
       //只需要移动一个盘子
       cout<<src<<"->"<<dest<<endl;
       return;
   }
    Hanoi(n-1,src,dest,mid);//将n-1个盘子从src移动到 mid
   cout<<src<<"->"<<dest<<endl;//再将一个盘子从src移动到 dest
    Hanoi(n-1,mid,src,dest);//再将n-1个盘子从mid移动到dest
    return;
}
int main(){
    Hanoi(2,'A','B','C');

    return 0;
}
