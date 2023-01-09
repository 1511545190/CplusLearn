//
// Created by 刘日亮 on 2023/1/8.
//
#include <stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    for(int a = 2;a<N;a++)
        for(int b = 2;b <a;++b)
            for(int c =b;c<a;++c)
                for(int d =c;d<a;++d)
                    if(a*a*a==b*b*b+c*c*c+d*d*d)
                        printf("triple(%d) = triple(%d,%d,%d)\n",a,b,c,d);


    return 0;
}
