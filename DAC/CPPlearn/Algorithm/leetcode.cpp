#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;
int MaxProfit(vector<int> prices){
    if(prices.size()==0||prices.size()<2)
        return 0;
    int length = prices.size();
    vector<vector<int> > dp;
    dp[0][1] = -prices[0];dp[0][0] = 0;
    for(int i-1;i<length;++i){
        //递推公式
        dp[i][0] = max<int>(dp[i-1][0],dp[i-1][1]+prices[i]);
        dp[i][1] = max<int>(dp[i-1][1],dp[i-1][0]-prices[i]);
    }
    return dp[length-1][0];//最后一天肯定时没有股票润最大
}
/* 
        for(int p = i;p< price.size()-2;p++){//in
            sum = 0;
            sum-=price[p];
            for(int out = p+1; out< price.size();out++){
                sum-=price[p];
            }
        } */
int main()
{
    vector<int> price = {7,1,5,3,6,4};
    int a[100][100];
 
    
    
    return 0;
}