// Problem Taken from:
//      https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {  // O(N*K)
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<int> min_prices(k+1, INT_MAX), max_profits(k+1, 0);
    for (int i = 0; i < (int)prices.size(); ++i) {
        for (int idx = 1; idx < k+1; ++idx) {
            min_prices[idx] = min(min_prices[idx], prices[i] - max_profits[idx-1]);
            max_profits[idx] = max(max_profits[idx], prices[i] - min_prices[idx]);
        }
    }
    return max_profits[k];
}

int main() {
    vector<int> prices1{2,4,1};  // ans = 2
    cout << "Case 1 : " << maxProfit(2,prices1) << "\n";

    vector<int> prices2{3,2,6,5,0,3};  // ans = 7
    cout << "Case 2 : " << maxProfit(2, prices2) << "\n";

    return 0;
}