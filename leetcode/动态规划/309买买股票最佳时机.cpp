// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

// 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
/*
        f[i] 表示 第i天【结束】之后的【累计最大收益】
        状态有3中，持有，未持有且处于冷冻期，没有持有并且不在冷冻期
                f[i][0] f[i][1] f[i][2]

        0: 目前持有的 可以 是在 i-1 天就已经持有
            第 i 天买入,那么i -1 天就不能持有股票不能处于冷冻期
            so: f[i][0] = max(f[i-1][0],f[i-1][2] - prices[i])
        1：第i天结束之后：未持有且处于冷冻期 可以 i天卖了票（i-1天必须有票）
        【今天卖了，明天不能买】 也就是两天的 maxProfit 是一样的
            so: f[i][1] = f[i-1][0] + prices[i]
        2：没有持有并且不在冷冻期,第i天没有任何操作
            i - 1 天没有持股 有两种情况
            so: f[i][2] = max(f[i-1][1],f[i-1][2])
        SO: max(f[n-1][0],f[n-1][1],f[n-1][2])
        */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: 手上持有股票的最大收益
        // f[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = -prices[0];
        for (int i = 1; i < n; ++i) {
            f[i][0] = max(f[i - 1][0], f[i - 1][2] - prices[i]);
            f[i][1] = f[i - 1][0] + prices[i];
            f[i][2] = max(f[i - 1][1], f[i - 1][2]);
        }
        return max(f[n - 1][1], f[n - 1][2]);
    }
};
