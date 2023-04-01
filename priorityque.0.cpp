#include <queue>
#include <iostream>
using namespace std;
int main(){
    priority_queue<double> pq1;
    for(int i = 0;i<10;++i){
        pq1.push(rand()%10);
    }
    while(!pq1.empty()){
        cout<<pq1.top()<<endl;
        pq1.pop();
    }
    
    priority_queue<double,vector<int>,greater<int> > pq2;
    for(int i = 0;i<10;++i){
        pq2.push(rand()%10);
    }
    while(!pq2.empty()){
        cout<<pq2.top()<<endl;
        pq2.pop();
    }
    cout<<"----"<<endl;
    vector<int> vec{1,2,3};
    cout<<*vec.begin()<<endl;
}