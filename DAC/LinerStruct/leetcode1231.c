//
// Created by 刘日亮 on 2022/12/31.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#define N 100;
int compare(const void* a, const void* b){
//    return *((int*)a) - *((int*)b);   //小的在前面
return *((int*)a) - *((int*)b);
}
void stripmore(int * num,int* size){
    int n  =*size;
    int j =0;
    int count =0;
    for(int i = 0;i<n;i++){
        //当不相等时刻
        if(num[j] != num[i]){
            num[j+1]= num[i];
            j++;

            count++;
        }


        //当相等时刻i继续往前走

    }
    *size = count;
}
void createrandnum(int *num,int n){
    srand(time(NULL));
    for(int i = 0;i<n;i++)
        num[i] = rand()%100;
}
int main()
{

    int num[100] = {11,11,22,33,4,4,55,0,10,3,2};
    int n =10;

    for(int i = 0;i<n;i++)
        printf("%d ",num[i]);
    printf("\n");
//    memset(num,0,sizeof (num));

    qsort(num,n,sizeof(int),compare);
    for(int i = 0;i<n;i++)
        printf("%d ",num[i]);
    printf("\n");
    stripmore(num,&n);
    for(int i = 0;i<n;i++)
        printf("%d ",num[i]);
    return 0;
}
