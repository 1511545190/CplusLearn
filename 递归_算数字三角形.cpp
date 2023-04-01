#include <iostream>
using namespace std;
#define N 3
int value = 0;
int max_sum (int nums[][100] ,int i, int j){
    if(i == N )
        return nums[i][j];
    return nums[i][j]+ max(max_sum(nums,i+1,j),max_sum(nums,i+1,j+1));
}
int main(){
    int nums[100][100];
    for(int i = 0;i<3;++i)
    {
        for(int j=0;j<=i;++j)
        cin >> nums[i][j];
    }

    cout<<endl<<max_sum(nums,0,0);
    return 0;
}