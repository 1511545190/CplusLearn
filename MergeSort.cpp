// #include <iostream>
// using namespace std;
void Merge(int a[], int s, int m, int e, int tmp[])
{
    //tmp 有序
    //将数组的局部a[s,m] 和 a[m+1,e] 合并到tmp
    int pb = 0;
    int p1 =s ,p2 = m+1;
    while(p1<= m && p2<= e)
    {
        if(a[p1] < a[p2]){
            tmp[pb++] = a[p1++];
        }else{
            tmp[pb++] = a[p2++];
        }
    }
    while(p1<=e){
        tmp[pb++] = a[p1++];
    }
    while(p2<=e){
        tmp[pb++]  = a[p2++];
    }
}
void MergeSort(int a[], int s, int e, int tmp[]){
    if(s<e){
        int m = s+ (e-s)/2;
        MergeSort(a,s,m,tmp);
        MergeSort(a,m+1,e,tmp);
        Merge(a,s,m,e,tmp);
    }
}