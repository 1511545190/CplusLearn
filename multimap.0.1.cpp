//学生成绩录入和查询系统
#include <map>
#include <string>
#include <iostream>
using namespace std;
class CStudent{
public:
    struct Info{
        string name;
        int id;
    };
    int score;
    Info info;
};
typedef multimap<int, CStudent::Info> MAP_STD;
void test();
int main(){
    test();
    //按分数查，那么分数为关键字
    cout<<"Please input Q/A to query or add information"<<endl;
    MAP_STD mp;
    CStudent student;
    string cmd;
    while(cin>> cmd){
        if(cmd == "A")
        {
            cout<<"please input name id score:";
            cin>>student.info.name>> student.info.id>> student.score;
        }
        else if(cmd == "Q"){
            int score;
            cout<<"please input socre:";
            cin>> score;
            MAP_STD::iterator p  = mp.lower_bound(score);
            MAP_STD::iterator maxp = p;
            int maxID;
            if(p!= mp.begin())//找到了
            {
                --p;
                score= p->first;
                maxID = p->second.id;//找最大ID
            }
            for(;p!=mp.begin()&&p->first==score;--p){
                if(p->second.id > maxID){
                    maxp = p;
                    maxID = p->second.id;
                }
            }
            //.....
            
        }


    }
}
