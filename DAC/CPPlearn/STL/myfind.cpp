//
// Created by 刘日亮 on 2023/2/7.
//
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> save = nums;
        for(int i = 0;i< nums.size();++i){
            int index = i+(i+k)%nums.size();
            nums[index] = save[i];
        }

    }

};
