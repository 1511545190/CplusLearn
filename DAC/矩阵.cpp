//
// Created on 2023/1/6.
//
#include <stdio.h>
#include <stdlib.h>

#define M 3  //这里修改行列
#define N 3
typedef int T;
/*
typedef struct Matrix{
    int rows,columns; //最大行数，最大列数
    int m,n;//
    T* data;
}MX;
int initial(MX* matrix,int rows,int coloums){
    matrix = (MX*) malloc(sizeof (MX));
    matrix->m=rows;
    matrix->n=coloums;
    matrix->data = (T*) malloc(sizeof (T)*rows*coloums);

}
int add(int value,MX* matrix){

}
*/

//打印矩阵 M 行 N 列
//* 右结合 [] 右结合
//打印二阶矩阵
void PrintMatrix(T (*matrix)[N]) {
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%-4d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}
int main() {
    printf("matrix 1\n");
    T matrix[M][N] = {
            1, 2, 3,
            4, 5, 6,
            7, 8, 9,

    };
    PrintMatrix(matrix);
    printf("matrix 2\n");
    T matrix2[M][N] = {
            1, 1, 0,
            0, 1, 0,
            0, 0, 1,

    };
    PrintMatrix(matrix2);


    T resalut[M][N];
    printf("PLUS\n");
    //加法
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            resalut[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }
    PrintMatrix(resalut);


    printf("C*matrix\n");
    //数乘
    int C = 3;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            resalut[i][j] = matrix[i][j] * C;
        }
    }
    PrintMatrix(resalut);


    //矩阵乘法
    printf("multiply:\n");
    T result[100][100] = {0};
    int m1_m = M;
    int m1_n = N;

    int m2_m = M;
    int m2_n = N;

    if (m1_n == m2_m)//可乘
        for (int i = 0; i < m1_m; i++) {//结果矩阵 行数 等于第一个矩阵的行数
            for (int j = 0; j < m2_n; j++) {//列数等于第二个矩阵的列数

                for (int k = 0; k < m1_n; k++)
                    result[i][j] += (matrix2[i][k] * matrix[k][j]);//每一个元素都有n项

                printf("%-4d", result[i][j]);//即刻输出
            }
            printf("\n");
        }
    //遍历，不能再用print函数



    //矩阵转置//只有方阵才能原地转化
    printf("Turn:\n");
    T turn[100][100] = {0};
    for (int i = 0; i < m1_m; ++i) {
        for (int j = 0; j < m1_n; ++j) {
            //a(i,j) = a(j,i)
            turn[i][j] = matrix[j][i];
            printf("%-4d", turn[i][j]);
        }
        printf("\n");
    }

    //竖直翻转
    printf("Vertical:\n");
    for (int i = 0; i < m1_m; ++i) {
        for (int j = 0, j_end = m1_n - 1; j != j_end; ++j, --j_end) {
            T temp = matrix[i][j];
            matrix[i][j] = matrix[i][j_end];
            matrix[i][j_end] = temp;
        }
    }
    PrintMatrix(matrix);
    //水平翻转
    printf("Horizontal:\n");
    for (int i = 0; i < m1_n; ++i) {
        for (int j = 0, j_end = m1_m - 1; j != j_end; ++j, --j_end) {
            T temp = matrix[j][i];
            matrix[j][i] = matrix[j_end][i];
            matrix[j_end][i] = temp;
        }
    }
    PrintMatrix(matrix);
    //水平+竖直 = 180°（顺时针）
    //矩阵乘法也可翻转

    //竖直 + 水平 = 180 °（逆时针)

    /*
    printf("result: %d\n",result[0][2]);

    printf("sizeof(matrix) : %d\n", sizeof(matrix));
    printf("sizeof(matrix[0]) : %d\n", sizeof(matrix[0]));


    printf("**matrix: %d\n", **matrix);
    printf("*(*(matrix +1)+1) : %d\n", *(*(matrix + 1) + 1));
     */
    return 0;
}