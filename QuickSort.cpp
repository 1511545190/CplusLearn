#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a= b;
    b= temp;
}
void QucickSort(int a[], int s,int e)
{
    if(s>=e){
        return ;
    }

    int k = a[s];
    int i = s , j =e;
    while(i!=j){
        while(j>i&& a[j]>= k)//找小值，结束时为j=i或者，a[j]<k
            --j;
        swap(a[i],a[j]);

        while(j>i&& a[i] <= k)//找大值
            ++i;
        swap(a[i],a[j]);
    }//经过了两次交换，a[i] <=> k ( i到了中间位置)
    QucickSort(a,s,i-1);
    QucickSort(a,i+1,e);
}
int main()
{
    
    return 0;
}