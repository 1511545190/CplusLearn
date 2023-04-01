//
// Created by 刘日亮 on 2023/1/6.
//
#include <iostream>

using namespace std;

//模板
template<typename T, typename T2>
void Swap(T &a, T &b, const T2 c) {
    T t = a;
    a = b;
    b = t;
    cout << c << endl;
}

void test() {
    int a, b;
    int *p = &a;

    //int const * 也一样
    const int *constint = &a; //值不能通过指针改

    //*constint = 12;错误
    constint = &b;
    int *const intconst = &a;//指针不能再指
    *intconst = 12;
    //intconst = &b;错误


}

int main() {
    int a1 = 2, b1 = 3;
    Swap(a1, b1, "first invoke");
    cout << a1 << " " << b1 << endl;
    double a2 = 2.11, b2 = 9.85;
    Swap(a2, b2, "second invoke");//自动推导，所有各自参数类型需要一致
    cout << a2 << " " << b2 << endl;
    Swap<int, const char * const>(a1, b1, "thirth invoke");//指定类型




    return 0;
}
