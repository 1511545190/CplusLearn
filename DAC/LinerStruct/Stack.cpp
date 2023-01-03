//
// Created by 刘日亮 on 2022/12/31.
//
#include <iostream>
#include <stack>
using  namespace std;
int main()
{
    stack<int> st;
    st.push(11);
    st.push(22);
    st.push(33);

    cout<<st.size()<<endl;

    int x;
    st.pop();
    x = st.top();   //返回引用

    cout<<x<<" "<<st.empty()<<endl;
    cout<<st.size()<<endl;



    return 0;
}