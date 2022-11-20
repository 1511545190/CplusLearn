#include "Myclass.h"   // 头文件的声明在其他文件实现了，可以直接拿头文件来用
#include <stdio.h>

int main(){

    library LB;
    LB.changecap(1000);

    //char ch[10]="NIHAO";
    //LB.nameit(ch);
    LB.showname();
    //LB.realtime_pupularity = 123;
    printf("%d \n",LB.realtime_pupularity);
    

    library *p = new library[3];
    delete[] p;




    return 0;
}
