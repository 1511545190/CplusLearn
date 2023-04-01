//
// Created by 刘日亮 on 2023/2/23.
//
#include <iostream>
#include <set>
#include <vector>
using namespace std;
bool containsDuplicate(vector<int>& nums) {
    set<int> container;
    for(auto i: nums){
        cout<<i<<endl;
        if(!container.insert(i).second){

            return false;

        }
    }
    return true;
}

int singleNumber(vector<int>& nums) {
    /*给你一个 非空 整数数组 nums ，除了某个元素只出现一次以外，
    其余每个元素均出现两次。找出那个只出现了一次的元素。
    你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。
    */

    vector<int > hash(nums.size()+1,0);// 下标为数字，值为次数
    for(auto i:nums)
    {
        hash[i]++;

        cout<<"hash["<<i<<"]"<<" "<<hash[i]<<endl;
    }
    for(auto i = 0;i<hash.size();++i)
    {
        if(hash[i]==1)//不重复
            return i;
    }
    return 0;
}
int main()
{
    vector<int> nums{4,1,2,1,2};
    cout<<singleNumber(nums);

}
