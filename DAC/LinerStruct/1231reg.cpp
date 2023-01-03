#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int main()
{
    //正则表达式
    string email = "abc@qq.com";

    regex r("正则表达式");
    cout<<regex_match(email,r)<<endl;
    
    return 0;
}