// Problem Taken from:
//      https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit_greedy(vector<int>& prices) {
    int max  = 0;
    int temp = 0;
    for (auto it = prices.begin(); it != prices.end(); ++it) {
        for (auto it2 = it + 1; it2 != prices.end(); ++it2) {
            temp = (*it2) - (*it);
            max  = (max < temp) ? temp : max;
        }
    }
    return max;
}

int maxProfit(vector<int>& prices) { // FASTEST SOLN BUT ONLY ONCE
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int min  = INT_MAX;
    int max  = 0;
    int temp = 0;
    for (auto it = prices.begin(); it != prices.end(); ++it) {
        min  = (min > *it) ? *it : min;
        temp = *it - min;
        max  = (max < temp) ? temp : max;
    }
    return max;
}

int maxProfit_alternative(vector<int>& prices) {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int min_price  = (*prices.begin());
    int max_profit = 0;
    for (auto it = prices.begin(); it != prices.end(); ++it) {
        min_price = std::min(min_price, *it);
        max_profit = std::max(max_profit, (*it - min_price));
    }
    return max_profit;
}

int maxProfit_memoryefficient(vector<int>& prices) { // CONSISTENTLY FASTER
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int min_price  = prices[0];
    int max_profit = 0;
    for (int it = 1; it < (int)prices.size(); ++it) {
        min_price  = min(min_price, prices[it]);
        max_profit = max(max_profit, (prices[it] - min_price));
    }
    return max_profit;
}

int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};  // ans = 5;
    cout << "Case 1 : " << maxProfit(prices) << "\n";

    vector<int> prices1{7, 6, 4, 3, 1};  // ans = 0
    cout << "Case 1 : " << maxProfit(prices1) << "\n";

    return 0;
}