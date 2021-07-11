//
// Created by 蒋澳然 on 2021/7/12.
// email: 875691208@qq.com
// $desc
//

#ifndef CPPALGORITHM_DPTEMPLATE_H
#define CPPALGORITHM_DPTEMPLATE_H

#include "BasicSTL.h"

/* LeetCode 188 */
/* 卖股票的最佳时机 */
/* 给定一个整数数组prices ，它的第 i 个元素prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1：

输入：k = 2, prices = [2,4,1]
输出：2
解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
示例 2：

输入：k = 2, prices = [3,2,6,5,0,3]
输出：7
解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 。

 * */

/* 核心思想就是状态表示和状态转移方程
 * 那么这个状态怎么来表示，这里我们用另外一种独到的思想来表示：
 * 最多参与k笔交易，那么我们用buy和sell表示交易的两种方式：买入股票和卖出股票 来表示手上持有的最大现金
 * 用buy[k]和sell[k]表示进行k笔交易手上持有的最大现金
 * 那么最后要求的结果就是sell[k]
 * 注意：这里有一个点要明确：我们在买入一个股票的时候，表示成立了一笔交易，此时k+1
 * 所以：
 * buy[k] = max(buy[k], sell[k - 1] - price.at(i))
 * 表示：买k笔股票所持有的现金最大值可以是 啥都不干(第一个参数buy[k]) 或者上一笔交易后所持有现金(sell[k - 1])后在当天再买入一股( - price.at(i))
 * 而：
 * sell[k] = max(sell[k], buy[k] + price.at(i))
 * 表示：卖k笔股票所持有的现金最大值可以是 啥都不干(第一个参数sell[k]) 或者上一笔买入一股后所持有现金(buy[k](代码中需要一个临时变量来保存))后在当天抛出( + price.at(i))
 * */

/* 所以股票模板这样写 */
int maxProfit(const vector<int> &prices, int k) {
    if (prices.empty()) return 0;   // 必须，判断空条件才能接下来赋值
    vector<int> buy(k + 1, -prices[0]);     // 买入，初始没钱，白手起家，买入都是欠债买，是prices的每一个元素取负数，这里是-prices[0]程序仍然运行是正确的，因为会更新
    vector<int> sell(k + 1, 0);     // 卖出，初始没钱，白手起家，所以全为0
    for (const int &p : prices) {
        for (int i = 1; i <= k; i++) {
            // 记录上一次的buy[i]
            int temp = buy[i];
            // 按照逻辑，股票是 先买 才能 后卖，所以我们先写买入股票
            // 注意，所有的限制条件(冷冻期/手续费)都会影响buy和sell的更新
            // 所以这两行代码会根据k的不同情况变化
            buy[i] = max(buy[i], sell[i - 1] - p);
            // 然后卖出，注意是上次持有的buy，因为代码中，buy[i]有可能变化
            sell[i] = max(sell[i], temp + p);
        }
    }
    // 返回k笔交易的最大值
    return sell[k];
}

// 第一种情况 k = 1
// k = 1
int maxProfit(const vector<int> &prices) {
    if (prices.empty()) return 0;
    int buy = -prices[0], sell = 0;     // k = 1, 我们不再需要k个的数组了，因为我们只能进行一次交易
    for (const int &p : prices) {
        int temp = buy;
        buy = max(buy, -p);     // 因为我们只能进行一次交易，所以我们买入股票的时候 全是 欠债 来买，所以这里是 -p
        sell = max(sell, temp + p);
    }
    return sell;
}

// k = +infinity
int maxProfit(const vector<int> &prices) {
    if (prices.empty()) return 0;
    int buy = -prices[0], sell = 0;     // k = +无穷, 我们不再需要k个的数组了，因为我们只能进行无数次，每次根据上一个状态更新即可
    for (const int &p : prices) {
        int temp = buy;
        buy = max(buy, sell - p);       // 因为我们可以无限次交易，所以buy的更新必须包含上一次sell的值，所以这里是 sell - p
        sell = max(sell, temp + p);
    }
    return sell;
}

// 常规
// k = 2
int maxProfit(const vector<int> &prices) {
    if (prices.empty()) return 0;
    int k = 2;
    vector<int> buy(k + 1, -prices[0]);
    vector<int> sell(k + 1, 0);
    for (const int &p : prices) {
        for (int i = 1; i <= k; i++) {
            int temp = buy[i];
            buy[i] = max(buy[i], sell[i - 1] - p);
            sell[i] = max(sell[i], temp + p);
        }
    }
    return sell[k];
}

// k = n
int maxProfit(int k, const vector<int> &prices) {
    if (prices.empty()) return 0;
    vector<int> buy(k + 1, -prices[0]);
    vector<int> sell(k + 1, 0);
    for (const int &p : prices) {
        for (int i = 1; i <= k; i++) {
            int temp = buy[i];
            buy[i] = max(buy[i], sell[i - 1] - p);
            sell[i] = max(sell[i], temp + p);
        }
    }
    return sell[k];
}

// 含一次冷冻期的交易
// k = +infinity with cooldown
int maxProfit(const vector<int> &prices) {
    if (prices.empty()) return 0;
    int buy = -prices[0], sell = 0;
    int sell_prev = sell;
    for (const int &p : prices) {
        int temp = sell;    // temp保存上上一次的sell，因为接下来sell有可能会变
        int temp2 = buy;
        buy = max(buy, sell_prev - p);      // 因为含一次冷冻期，所以buy的更新只能根据上上一次sell的值来
        sell = max(sell, temp2 + p);
        sell_prev = temp;
    }
    return sell;
}

// 带手续费的交易
// k = +infinity with fee
int maxProfit(const vector<int> &prices, int fee) {
    if (prices.empty()) return 0;
    int buy = -prices[0], sell = 0;
    for (const int &p : prices) {
        int temp = buy;
        buy = max(buy, sell - p);
        sell = max(sell, temp + p - fee);   // 带手续费的情况下，意味着每一次卖出（必有买入）要多付一笔钱
    }
    return sell;
}

#endif //CPPALGORITHM_DPTEMPLATE_H
