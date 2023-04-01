#include <iostream>
#include <map>
using namespace std;
int main(){
    typedef multimap<int,double,less<int> > mmid;
    mmid pairs;
    cout<<"1)" << pairs.count(15)<<endl;
    pairs.insert(mmid::value_type(15,2.7));
    pairs.insert(mmid::value_type(15,99.3));
    cout<<"2)" << pairs.count(15)<<endl;
    pairs.insert(mmid::value_type(30,1111));
    pairs.insert(mmid::value_type(10,2222));
    pairs.insert(make_pair(1,22222));


    for(mmid::const_iterator i = pairs.begin();i!=pairs.end();++i){

        cout<<"("<<i->first<<","<<i->second<<"), ";
    }
    cout<<endl;

    return 0;
}