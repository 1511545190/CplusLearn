//
// Created by 刘日亮 on 2023/2/13.
//
#include <iostream>
int step(int n){
    if(n==2) return 2;
    if(n==1) return 1;
    return step(n-1) + step(n-2);
}
using namespace std;
int main(){
    while(1){
        int a;
        cin >> a;
        cout<< step(a);
    }

    return 0;
}