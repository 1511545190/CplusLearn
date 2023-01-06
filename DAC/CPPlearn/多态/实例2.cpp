//
// Created by 刘日亮 on 2023/1/6.
//
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

class CShape {
    int x, y;
public:
    virtual double Area() = 0;//纯虚函数
    virtual void PrintInfo() = 0;
};

class CRectangle : public CShape {
public:
    int w, h;

    virtual double Area() {
        return w * h;
    }

    virtual void PrintInfo() {
        cout << "Rectangle: " << Area() << endl;
    }
};

class CCircle : public CShape {
public:
    int r;

    virtual double Area() {
        return 3.14 * r * r;
    }

    virtual void PrintInfo() {
        cout << "Circle: " << Area() << endl;
    }
};

class CTriangle : public CShape {
public:
    int a, b, c;

    virtual double Area() {
        double p = (a + b + c) / 2.0;//海伦公式
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    virtual void PrintInfo() {
        cout << "Triangle: " << Area() << endl;
    }
};

#define SHAPES_NUMBER 100
//s1 s2 指向 数组元素（指针类型），所以属于指针的指针
//这里的形式参数是编译器给的指针
int MyCompare(const void * const s1, const void * const s2){
    double a1,a2;
    CShape**p1,**p2;
    p1=(CShape**)s1;  //强制转换为二级指针才能对 *s1
    p2=(CShape**)s2;

    a1 = (*p1)->Area();
    a2 = (*p2)->Area();
    if(a1<a2)
        return -1;
    else if(a2<a1)
        return 1;   //若a2 > a1 则交换
    else
        return 0;
}
int main() {
    //输入几何形体的个数
    int number_of_shapes;
    cin >> number_of_shapes;

    //对各个几何形体排序
    //所以要先准备存储的容器
    CShape *pShapes[SHAPES_NUMBER];
    //各个对象的指针
    CRectangle *pRectangle;
    CCircle *pCircle;
    CTriangle *pTriangle;

    for (int i = 0; i < number_of_shapes; i++) {
        //选项卡
        char option;
        cin >> option;
        switch (option) {
            case 'R':
                pRectangle = new CRectangle();
                cin >> pRectangle->w
                    >> pRectangle->h;
                pShapes[i] = pRectangle;
                break;
            case 'C':
                pCircle = new CCircle();
                cin >> pCircle->r;
                pShapes[i] = pCircle;
                break;
            case 'T':
                pTriangle = new CTriangle();
                cin >> pTriangle->a
                    >> pTriangle->b
                    >> pTriangle->c;
                break;
            default:
                cout << "no choice" << endl;
                break;
        }
    }

    //qsort 排序 起始，+n ，每个元素的大小
    qsort(pShapes,number_of_shapes,sizeof (CShape*), MyCompare);
    for(int i=0;i<number_of_shapes;i++)
        pShapes[i]->PrintInfo();
    return 0;
}

