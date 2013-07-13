#ifndef _BUY_SELL_STOCK2_H_
#define _BUY_SELL_STOCK2_H_

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0) {
            return 0;
        }

        int max_profit = 0;
        int buy_pos = -1;
        int sell_pos = -1;

        for (size_t i = 0; i < prices.size(); i++) {
            if (buy_pos == -1) {
                buy_pos = sell_pos = i;
                continue;
            }

            if (buy_pos == sell_pos) {
                if (prices[i] < prices[buy_pos]) {
                    sell_pos = buy_pos = i;
                } else {
                    sell_pos = i;
                }
            } else {
                if (prices[i] < prices[sell_pos]) {  // sell
                    max_profit += prices[sell_pos] - prices[buy_pos];
                    sell_pos = buy_pos = i;
                } else {
                    sell_pos = i;
                }
            }
        }

        if (sell_pos == prices.size() -1) {
            max_profit += prices[sell_pos] - prices[buy_pos];
        }

        return max_profit;
    }
};

#endif
