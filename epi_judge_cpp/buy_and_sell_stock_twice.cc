#include <vector>
#include "test_framework/generic_test.h"

using namespace std;

double BuyAndSellStockTwice(const vector<double> &prices) {
    /*
     * Solution from LeetCode discussions
     * Assume I have ₹0
     * Buy first stock -> Money I have = -buy1 (loaned ₹buy1)
     * Sell first stock -> Money I have = prices[i] - (-buy1) = sell1
     * Buy second stock -> Money I have = sell1 - prices[i] = buy2
     * Sell second stock -> Money I have = prices[i] - buy2 = sell2
     * Maximize sell2
     */
    // NOTE: Use numeric_limits::lowest(), not min()
    double buy1, sell1, buy2, sell2;
    buy1 = buy2 = numeric_limits<double>::lowest();
    sell1 = 0.0, sell2 = 0.0;
    for(double price: prices) {
        buy1 = max(buy1, -price);
        sell1 = max(sell1, buy1 + price);
        buy2 = max(buy2, sell1 - price);
        sell2 = max(sell2, buy2 + price);
    }
    return sell2;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"prices"};
    return GenericTestMain(args, "buy_and_sell_stock_twice.cc",
                           "buy_and_sell_stock_twice.tsv", &BuyAndSellStockTwice,
                           DefaultComparator{}, param_names);
}
