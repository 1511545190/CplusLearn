//
// Created by 刘日亮 on 2023/1/8.
//
//dec oct hex
//set base 指定进制输出
#include <iomanip>
#include <iostream>

using namespace std;

void test1() {
    int n = 10;
    cout << n << endl;
    cout << hex << n << "\n"//连续起作用
         << dec << n << "\n"
         << oct << n << "\n";
    return;
}

void test2() {

    cout.precision(10);
    //精度
    cout << setprecision(5);//连续起作用

    double x = 123421.1234567, y = 324142.4231;
    int n = 2342;
    int m = 23;
    //缺省非定点，六位有效数字
    //那么第一个只能输出科学计数法
    cout << setprecision(6) << x << endl
         << y << endl << n << endl << m << endl;

    //以定点方式控制小数点后面的数字
    x = 123.231;
    //补零，太长四舍五如
    cout << setiosflags(ios::fixed) <<
         setprecision(6) << x << endl
         << y << endl << n << endl << resetiosflags(ios::fixed) <<
         x << endl;

    return;
}

void test3() {
    //set width
    //cin>>setw(4)
    //cin.width   //一次性设置
    int w = 4;
    char string[10];
    cin.width(5);
    //包含了结尾的\0,只读了4个字符，其他在缓冲区
    //所以这里只用输入一次，循环直到到达结尾
    while (cin >> string) {
        cout.width(w++);//空格左边补位
        cout << string << endl;
        cin.width(5);
    }

}

void test4() {
    int n = 141;
    cout << "1)" << hex << n << "" << dec << n << " " << oct << endl;
    double x = 1234567.89, y = 12.34567;
    //保留5位有效数字
    cout << "2)" << setprecision(5) << x << " " << y << " " << endl;
    //保留小数点后面5位
    cout << "3)" << fixed << setprecision(5) << x << " " << y << " " << endl;
    //科学计数法，并且保留小数点后5位
    cout << "4)" << scientific << setprecision(5) << x << " " << y << " " << endl;
    //非负数显示正，输出宽度为12，宽度不足则用’*‘补足
    cout<<"5)"<<showpos<<fixed<<setw(12)<<setfill('*')<<12.1<<endl;
    //非负数不显示正号,左对齐
    cout<<"6)"<<noshowpos<<setw(12)<<left<<12.1<<endl;
    //right internal,填充到’-‘和数字中间

}

int main() {
    test1();
    test4();
    return 0;
}


void test5(){
    //自定义算子
    ostream &tab(ostream &output);

}
ostream &tab(ostream &output){//参数和返回值都固定！
    //output 是 cout

    return output <<'\t';
}
