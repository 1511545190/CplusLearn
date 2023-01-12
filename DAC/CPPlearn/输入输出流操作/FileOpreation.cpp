//
// Created by 刘日亮 on 2023/1/8.
// windows 斌不是文本文件，那么要用ios::binary ,
#include <fstream>//包含头文件
#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

//创建文件
//标志:按位方式存储
//同时设上若干个标志
//out 输出，删除原有
//app append
void test() {

    ofstream outFile("clients.dat", ios::out | ios::binary);//利用构造函数打开
    if (!outFile) {
        cout << "File open error\n";
    }

    outFile.close();
}

void test1() {
    //seek 移动
    ofstream fout;
    fout.open("a.out", ios::app);
    //文件指针
    long location = fout.tellp();//tell pointer
    location = 10;
    fout.seekp(location);//把文件指针移动到第10个字节的位置
    fout.seekp(location, ios::beg);//相对于开始位置


    //ate read at end
    ifstream fin("a1.in", ios::ate);
    location = fin.tellg();//获取指针的位置
    location = 10L;//location 可以为负值
    fin.seekg(location);

    /*ios::end
  ios::cur//当前位置
   */

}

//in.txt sort -> out.txt
void test2() {

    vector<int> v;
    ifstream srcFile("in.txt", ios::in);
    if (!srcFile) {
        cout << "cant open\n" << endl;
        return;
    }
    ofstream desFile("out.txt", ios::out);
    int x;
    while (srcFile >> x)
        v.push_back(x);

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        desFile << v[i] << " ";//存到缓冲区，缓冲区满了才访问硬盘
    }
    desFile.close();
    srcFile.close();
}

void read_write() {
    //read \write
    //binary
    ofstream fout("in.txt", ios::out | ios::binary);
    int x = 120;
    //enforce change the date type
    fout.write((const char *) (&x), sizeof(x));//then it will move automatic
    fout.close();

    //open binary
    ifstream fin("in.txt", ios::in | ios::binary);
    int y;
    fin.read((char *) (&y), sizeof(y));
    cout << y << endl;
}

// input : several students' scores and names
// store form: binary form in file
void stu_binary() {
    ofstream out("in.txt", ios::out | ios::binary);
    struct stu {
        char name[100];
        int score;
    } student;
    while (cin >> student.name >> student.score)
        out.write((const char *) (&student), sizeof(student));
    out.close();

    //read
    ifstream in("in.txt", ios::in | ios::binary);
    while (in.read((char *) &student, sizeof(student))) {
        //How many bytes have read hitherto
        int readBytes = in.gcount();
        cout << student.name << " " << student.score << endl;
        cout << "count: " << readBytes << endl;
    }
    in.close();

}
/*
 * read \write
Tom 60
count: 104
Jeck 80
count: 104
  */
//read and write : change Jeck to Mike
void RBW() {
    struct stu {
        char name[100];
        int score;
    } student;

    //from 0
    // student 0 , 1, 2
    fstream iofile("in.txt", ios::in | ios::out | ios::binary);
    if (!iofile) {
        cout << "error";
        return;
    }

    //记录从0开始编号
    iofile.seekp(2 * sizeof(student), ios::beg);//写指针移动
    //！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
    iofile.write("Mike", strlen("Mike") + 1);//+1 将/0写了进去，形成字符串

    iofile.seekg(0, ios::beg);//读指针定位到文件开头
    while (iofile.read((char *) &student, sizeof(student)))
    cout << student.name << " " << student.score << endl;

    iofile.close();
}

void MyCopy(int argc, char* argv[]){
    if(argc !=3){//命令行参数的个数，包括程序本身
        cout<<"File name missing"<<endl;
        return;
    }
    ifstream src(argv[1],ios::binary|ios::in);
    ofstream des(argv[2],ios::binary|ios::out);
    if(!des){
        cout<<"cant open\n";
        return;}

    //读写循环
    char temp;
    while(src.get(temp))
        des.put(temp);

    src.close();
    des.close();
    return;



}

int main(int argc,char * argv[]) {

//    stu_binary();
//    RBW();

    MyCopy(argc,argv);
    return 0;

}
