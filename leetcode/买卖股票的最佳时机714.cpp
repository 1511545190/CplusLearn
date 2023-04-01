//
// Created by 刘日亮 on 2023/3/23.
//
#include "leetcode.h"
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //卖出需要手续费
        //状态变量：日期、手中是否含有股票
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2));
        //创建二维数组，第一维度为日期状态，第二维度为股票含有状态
        //卖出股票需要交易费
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for(int i = 1;i<n;++i){
            dp[i][0] = //没有股票的情况 可能是
                    max(dp[i-1][0],                 //之前就没有
                        dp[i-1][1] + prices[i] -fee);//之前有，今天卖了
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
};