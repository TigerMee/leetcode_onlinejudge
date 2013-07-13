#ifndef _BUY_SELL_STOCK_H_
#define _BUY_SELL_STOCK_H_

#include <vector>

using namespace std;

class Solution {
public:
    class BS {
    public:
        int _bp; // buy position
        int _sp; // sell position
        int _profit;
        BS() : _bp(-1), _sp(-1), _profit(0) {}
        void set(int bp, int sp, int profit) {
            _bp = bp;
            _sp = sp;
            _profit = profit;
        }
    };

    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.size() == 0) {
            return 0;
        }

        BS bs1, bs2;

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
                    int profit = prices[sell_pos] - prices[buy_pos];
                    check_mp(bs1, bs2, buy_pos, sell_pos, profit, prices);

                    sell_pos = buy_pos = i;
                } else {
                    sell_pos = i;
                }
            }
        }

        if (sell_pos == prices.size() -1) {
            int profit = prices[sell_pos] - prices[buy_pos];
            check_mp(bs1, bs2, buy_pos, sell_pos, profit, prices);
        }

        return bs1._profit + bs2._profit;
    }

    void check_mp(BS &bs1, BS &bs2,
                int buy_pos, int sell_pos, int profit,
                vector<int> &prices) {
        if (bs1._bp == -1) {
            bs1.set(buy_pos, sell_pos, profit);
        } else if (bs2._bp == -1) {
            bs2.set(buy_pos, sell_pos, profit);
        } else {
            if ((bs2._sp == buy_pos - 1)
                && prices[buy_pos] >= prices[bs2._bp]
                && prices[sell_pos] >= prices[bs2._sp]) {   // bs2和current可以merge
                // 这里可以merge bs2和当前的profit
                // 但是要先检查bs1和bs2是否可以merge
                // 以及bs2如果不和profit merge是否更优
                const int BS12_CUR = 1;
                const int BS1_BS2CUR = 2;
                const int BS2_CUR = 3;
                if (can_merge(bs1, bs2, prices)) {
                    // 如果bs1和bs2也可以merge，有三种情况
                    // 1. bs1 + bs2, current
                    // 2. bs1, bs2 + current
                    // 3. bs2, current
                    int type = BS12_CUR;
                    int max_profit = prices[bs2._sp] - prices[bs1._bp] + profit;

                    if ((bs1._profit + prices[sell_pos] - prices[bs2._bp]) >= max_profit) {
                        type = BS1_BS2CUR;
                        max_profit = bs1._profit + prices[sell_pos] - prices[bs2._bp];
                    }
                    if ((bs2._profit + profit) >= max_profit) {
                        type = BS2_CUR;
                        max_profit = bs2._profit + profit;
                    }

                    switch(type) {
                        case BS12_CUR:  // merge bs1 and bs2, change bs2
                            bs1.set(bs1._bp, bs2._sp, prices[bs2._sp] - prices[bs1._bp]);
                            bs2.set(buy_pos, sell_pos, profit);
                            break;
                        case BS1_BS2CUR:    // merge bs2 and current.
                            bs2.set(bs2._bp, sell_pos, prices[sell_pos] - prices[bs2._bp]);
                            break;
                        case BS2_CUR:
                            bs1.set(bs2._bp, bs2._sp, prices[bs2._sp] - prices[bs2._bp]);
                            bs2.set(buy_pos, sell_pos, profit);
                            break;
                        default:
                            break;
                    }
                } else {
                    // 如果bs1和bs2不能merge，有两种情况
                    // 1. bs1, bs2 + current
                    // 2. bs2, current
                    int type = BS1_BS2CUR;
                    int max_profit = bs1._profit + prices[sell_pos] - prices[bs2._bp];

                    if ((bs2._profit + profit) >= max_profit) {
                        type = BS2_CUR;
                        max_profit = bs2._profit + profit;
                    }

                    switch (type) {
                        case BS1_BS2CUR:    // merge bs2 and current.
                            bs2.set(bs2._bp, sell_pos, prices[sell_pos] - prices[bs2._bp]);
                            break;
                        case BS2_CUR:
                            bs1.set(bs2._bp, bs2._sp, prices[bs2._sp] - prices[bs2._bp]);
                            bs2.set(buy_pos, sell_pos, profit);
                            break;
                        default:
                            break;
                    }
                }
            } else if (profit > bs1._profit || profit > bs2._profit) {
                // bs2和current不能merge。如果current比bs1或者bs2大，则有三种情况
                // 1. bs1 + bs2, current
                // 2. bs1, current
                // 3, bs2, current

                const int BS1_CUR = 1;
                const int BS2_CUR = 2;
                const int BS12_CUR = 3;

                int type = BS1_CUR;
                int max_profit = bs1._profit + profit;

                if (bs2._profit > bs1._profit) {
                    type = BS2_CUR;
                    max_profit = bs2._profit + profit;
                }
                if (can_merge(bs1, bs2, prices)
                    && (prices[bs2._sp] - prices[bs1._bp] + profit) > max_profit) {
                    type = BS12_CUR;
                    max_profit = prices[bs2._sp] - prices[bs1._bp] + profit;
                }

                switch (type) {
                case BS1_CUR:
                    bs2.set(buy_pos, sell_pos, profit);
                    break;
                case BS2_CUR:
                    bs1.set(bs2._bp, bs2._sp, bs2._profit);
                    bs2.set(buy_pos, sell_pos, profit);
                    break;
                case BS12_CUR:
                    bs1.set(bs1._bp, bs2._sp, prices[bs2._sp] - prices[bs1._bp]);
                    bs2.set(buy_pos, sell_pos, profit);
                    break;
                default:
                    break;
                }
            }
        }

        return;
    }

    bool can_merge(BS &bs1, BS &bs2, vector<int> &prices) {
        return prices[bs2._bp] >= prices[bs1._bp]
                && prices[bs2._sp] >= prices[bs1._sp];
    }
};
#endif // _BUY_SELL_STOCK_H_
