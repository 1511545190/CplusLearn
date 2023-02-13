#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
void swap(int &a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
void arrangeRight(vector<int> nums,int s,int e,int k){
    int i =s,j=e;
    int key = nums[s];
    //类快排操作
    while(i<j){
        while(i<j && nums[i] < key)
            i++;
        swap(nums[i],nums[j]);
        while(i<j && nums[j] > key)
            --j;
        swap(nums[i],[j]);        
    }

    int a = nums.size()-s;//包括key在内的a个
    if(a == k) return;
    else if(a > k)
        arrangeRight(nums,i,j,k);
    else 
        arrangeRight(nums,i,j,k-a);
}
int main()
{
    return 0;
}