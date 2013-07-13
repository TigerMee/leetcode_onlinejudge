#ifndef _BUY_SELL_STOCK_H_
#define _BUY_SELL_STOCK_H_

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
        int min_buy = prices[0];

        for (int i = 1; i < (int)prices.size(); i++) {
            if (prices[i] >= min_buy) {
                int profit = prices[i] - min_buy;
                if (profit > max_profit) {
                    max_profit = profit;
                }
            } else {
                min_buy = prices[i];
            }
        }

        return max_profit;
    }
};

#endif // _BUY_SELL_STOCK_H_
