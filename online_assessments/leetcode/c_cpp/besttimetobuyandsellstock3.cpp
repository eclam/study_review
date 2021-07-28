// Problem Taken from:
//      https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit_greediest(vector<int>& prices) {  // O(N^2)
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n = (int)prices.size(), max_profit = 0, left_sub_max_profit = 0, right_sub_max_profit = 0, min_price;

    for (int splitter = 0; splitter < n; ++splitter) {
        min_price           = prices[0];
        left_sub_max_profit = 0;
        for (int i = 0; i < splitter; ++i) {  // Left Subarray
            min_price           = min(min_price, prices[i]);
            left_sub_max_profit = max(left_sub_max_profit, prices[i] - min_price);
        }
        min_price            = prices[splitter];
        right_sub_max_profit = 0;
        for (int k = splitter; k < n; ++k) {  // Right Subarray
            min_price            = min(min_price, prices[k]);
            right_sub_max_profit = max(right_sub_max_profit, prices[k] - min_price);
        }
        max_profit = max(max_profit, right_sub_max_profit + left_sub_max_profit);
    }
    return max_profit;
}

int maxProfit_greedy(vector<int>& prices) {  // O(K*N) or O(N*LOGN)
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int n = (int)prices.size(), max_profit = 0, left_sub_max_profit = 0, right_sub_max_profit = 0, left_min_price = prices[0], right_min_price;

    for (int i = 1; i < n; ++i) {  // LEFT SIDE
        left_min_price      = min(left_min_price, prices[i]);
        left_sub_max_profit = max(left_sub_max_profit, prices[i] - left_min_price);

        right_min_price      = prices[i];
        right_sub_max_profit = 0;
        for (int k = i + 1; k < n; ++k) {  // RIGHT SIDE
            right_min_price      = min(right_min_price, prices[k]);
            right_sub_max_profit = max(right_sub_max_profit, prices[k] - right_min_price);
        }
        max_profit = max(max_profit, right_sub_max_profit + left_sub_max_profit);
    }
    return max_profit;
}

/* Notes:
    - given soln from version 1, we know that we can find the max of a sub arr in O(N)
    - we can do this with consecutive buys by chaining them together
*/
int maxProfit(vector<int>& prices) {  // O(N)
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int max_profit = 0, first_buy_max = 0, second_buy_max = 0, first_min = INT_MAX, second_min = INT_MAX;
    for (int i = 0; i < (int)prices.size(); ++i) {
        first_min      = min(first_min, prices[i]);
        first_buy_max  = max(first_buy_max, prices[i] - first_min);
        second_min     = min(second_min, prices[i] - first_buy_max);
        second_buy_max = max(second_buy_max, prices[i] - second_min);
    }
    return second_buy_max;
}

int main() {
    vector<int> prices1{3, 3, 5, 0, 0, 3, 1, 4};  // ans = 6
    cout << "Case 1 : " << maxProfit(prices1) << "\n";

    vector<int> prices2{1, 2, 3, 4, 5};  // ans = 4
    cout << "Case 2 : " << maxProfit(prices2) << "\n";

    vector<int> prices3{7, 6, 4, 3, 1};  // ans = 0
    cout << "Case 3 : " << maxProfit(prices3) << "\n";

    vector<int> prices4{1};  // ans = 0
    cout << "Case 4 : " << maxProfit(prices4) << "\n";

    return 0;
}