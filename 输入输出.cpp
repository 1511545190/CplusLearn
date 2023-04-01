//
// Created by 刘日亮 on 2023/1/8.
//
/*
 *
 * */
#include <iostream>

using namespace std;

void test_getline(){

    int x;
    char buf[100];
    cin>>x;//不将空格和回车读入，仍在输入流

    //碰到回车会结束
    cin.getline(buf,90);//会自动添加\0
    cout<<buf<<endl;

}

int main() {
    int x, y;
    //将标准输出重定向到test文件
    cin >> x >> y;
    cout << x + y << endl;
    freopen("test.txt", "w", stdout);


    //将输入流重定向到stdin
    //freopen("test.txt","r",stdin);


    ////cin >> y;
//    cout<<"outPut:"<<y<<endl;

   /* getline(char *buf,int bufSize, char delim = '\n')
*/
   //超过buffer 会出错

   //cin.getline() = 1//未到行尾

   //int peek 返回下一个字符，但不从流中去掉

   //istream& putback(chac c) 将字符c 放回输入流

   //istream& ignore(int nCount, int delim = EOF)
   //从流中删去最多nCount个字符

    test_getline();


    return 0;
}
