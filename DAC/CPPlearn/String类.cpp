//
// Created by 刘日亮 on 2023/1/18.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

void io(){
    string input("input1 input2 input3");
    istringstream input_string(input);
    string s1,s2,s3;
    input_string >>s1,s2,s3;


    int a =10;

    ostringstream out_string;
    out_string << a<<endl;
    cout<< out_string.str();
}



void sub_str(){
    string s1("hello world"),s2;
    s2 = s1.substr(0,s1.size());

    s1.swap(s2);
    s1.erase(5);//删掉下标5后面的字符

    s1.replace(2,3,"haha");//将ll替换成haha
    s1.replace(2,3,"123",0,1);

    s1.insert(0,"start");
    s1.insert(3,"12345",3,2);

}

void find(){
    string s1("Hello world");
    s1.find("lo");//返回第一次找到的
    s1.rfind("lo");//从后开始找
    s1.find("wor",1);//从下标为1的地方开始找

    //找字符
    s1.find_first_of("abcd");//从abcd中任取一个找
    s1.find_last_of("abcd");
    s1.find_first_not_of("abcd");


}


void change_to_char(){
    string s1("hello world");
    printf("%s\n",s1.c_str());//返回const char*

    const char* p1 = s1.data();//返回char*
}






void intitial(){
    string str;
    string str2("hello");
    str = 's';
    cout<<"str "<<str<<endl;

}

void length(){
    string s("hello");
    cout<<s;
    cout<<s.length()<<endl;
}

void getLine(){
    string str;
    cin >> str;
    //不读走空格

    string s;
    getline(cin,s);
    cout<< s<<endl;
}

void copy(){
    string s1("cat"),s2,s3;
    s2 = s1;  //直接copy
    cout <<"s1 "<<s1
    <<"s2 "<<s2<<endl;

    //assign copy
    s3.assign(s1);
    cout<<s3<<endl;


    //assign partly copy
    s3.assign(s1,0,1);
    /*from 0 following 1*/
    cout<<s3<<endl;

    //single copy

    s3[0] = s1[2];
    cout<<s3<<endl;

    //to see
    for(int i = 0;i<s1.length();++i)
        cout<<s1.at(i);//会做范围检查,抛出异常
    cout<<endl;



}

void append(){
    string s1("string 1"),str2 = " string 2";
    s1.append("end");
    s1.append(str2);
    s1.append(str2,0,str2.size());
}


void compare(){
    string s1("string 1"),str2 = " string 2";
    s1>str2;
    s1<=str2;
    s1.compare(str2);
    s1.compare(0,1,str2,2,3);

}

int main()
{
//    getLine();
    copy();

    string s1 = "123";
    cout<< s1.length()<<" "<<s1.size()<<endl;


    return 0;




}