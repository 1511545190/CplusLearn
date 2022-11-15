#include "Myclass.h"   // 头文件的声明在其他文件实现了，可以直接拿头文件来用
#include <stdio.h>
library LB;
int main(){
    LB.changecap();
    char ch[10]="NIHAO";
    LB.nameit(ch);
    LB.showname();
    LB.realtime_pupularity = 123;
    printf("%d \n",LB.realtime_pupularity);
    return 0;
}
