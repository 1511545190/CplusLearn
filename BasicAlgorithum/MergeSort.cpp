#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> temp;
    void mergeSort(vector<int>& nums, int l ,int r){
        if(l>=r) return;//because mid may over r
        int mid = l + (r -l)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        /*then nums of left and nums of right all sorted*/
        //merge
        int i = l,j = mid +1;
        int index = 0;
        while(i<=mid&& j<=r ){
            if(nums[i]>nums[j])
                temp[index++] =nums[j++];
            else
                temp[index++] = nums[i++];
        }
        while(i<=mid)
            temp[index++] = nums[i++];
        while(j<=r)
            temp[index++] = nums[j++];
        /*copy every single part*/
        // temp from 1 but nums form left
        for(int i = 0;i<r-l+1;++i) nums[l+i]=temp[i];
    }
    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size(),0);
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

class solution {
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1;
        int cnt = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[cnt++] = nums[i++];
            }
            else {
                tmp[cnt++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[cnt++] = nums[i++];
        }
        while (j <= r) {
            tmp[cnt++] = nums[j++];
        }
        for (int i = 0; i < r - l + 1; ++i) {
            nums[i + l] = tmp[i];
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize((int)nums.size(), 0);
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }
};







int main(){
    //nums arry
    vector<int> arry {5,2,3,1};
    Solution ans;
    ans.sortArray(arry);
    for(auto i: arry)
        cout<<i<<endl;
    return  0;   
}
