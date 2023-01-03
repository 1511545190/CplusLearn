//
// Created by 刘日亮 on 2022/12/31.
//
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    q.push(11);
    q.push(22);
    q.push(33);
    cout<<q.front()<<endl;
    int x;
    x = q.front();
    cout<<x<<endl;
    q.pop();
//    q.pop();
    x=q.front();  //pop 完11后，front 变为 22
    cout<<x<<endl;

    //银行
    //模拟叫号
    int N;
    cin >> N;
    cout<<"N: "<<N<<endl;
    string opration, id;
    queue<string> queue1;
    cin>>opration;//空格打断施法

    while(opration!="#"){
        cin>>id;
        if(opration=="In"){
            if (queue1.size() == N) {
                cout << "rejected. :" << id << endl;
            } else{
                queue1.push(id);
                cout<<id<<" joined \n"<< queue1.size()<<endl;
            }
        }else{
            if(queue1.empty()){
                cout<<" No one\n";
            }else{
                id=queue1.front();//查看
                queue1.pop();
                cout<<id<< " called";
                cout<<"total :"<<queue1.size()<<endl;
            }
        }
        cin >>opration;

    }



    return 0;
}