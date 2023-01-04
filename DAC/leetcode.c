#include <stdio.h>
#include <string.h>
#define N 10
#define M 5
int main()
{

    int i; //循环变量
    int count = 1;
    int arry[N][M];

    /*循环中的变量*/
    int start = 0;       //行标起始点(关键点）
    int row_end = N -1;  //行尾下标
    int column_end = M -1; //列尾下标

    while(count<=N*M) { //循环条件
        for (i = start; i < column_end +1; i++)
            arry[start][i] = count++;

        for (i = start + 1; i < row_end +1; i++)
            arry[i][column_end] = count++;

        for (i = column_end - 1; i >= start; i--)
            arry[row_end][i] = count++;

        for (i = row_end -1; i >= start + 1; i--)
            arry[i][start] = count++;

        start++;
        column_end--;
        row_end--;
    }

    //打印数组
    for(i =0;i<N;++i){
        for(int j=0;j<M;++j){
            printf("%-4d ",arry[i][j]);
        }
        printf("\n");
    }




    return 0;
}