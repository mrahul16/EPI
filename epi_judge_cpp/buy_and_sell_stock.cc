#include <vector>
#include "test_framework/generic_test.h"

using std::vector;
using std::max;
using std::min;

double BuyAndSellStockOnce(const vector<double> &prices) {
    double maxDifference = 0.0;
    double minBuyPrice = prices[0];
    unsigned int len = prices.size();
    for(int i = 1; i < len; i++) {
        maxDifference = max(maxDifference, prices[i] - minBuyPrice);
        minBuyPrice = min(minBuyPrice, prices[i]);
    }
    return maxDifference;
}

int main(int argc, char *argv[]) {
    std::vector<std::string> args{argv + 1, argv + argc};
    std::vector<std::string> param_names{"prices"};
    return GenericTestMain(args, "buy_and_sell_stock.cc",
                           "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                           DefaultComparator{}, param_names);
}
