//
// Created by 刘日亮 on 2023/1/31.
//

//迭代器
#include <iostream>
#include <vector>
using  namespace std;

void ite(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    vector<int>::const_iterator i;
    for(i = v.begin();i!=v.end();i++)
        cout<<*i<<" ";
    cout<<endl;


    vector<int>::const_reverse_iterator r;
    for(r = v.rbegin();r!=v.rend();r++)
        cout<<*r<<" ";
    cout<<endl;

    vector<int>::iterator c;
    for(c=v.begin();c!=v.end();c++) {
        *c = *c * 100;
    }

    for(i = v.begin();i!=v.end();i++)
        cout<<*i<<" ";
    cout<<endl;

    vector<int> nums(100);
    int it;

    cout<<endl;
}

void function(){



}

int main(){
    ite();
    return 0;
}
