// Problem Taken from:
//      https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <climits>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int k, vector<int>& prices) {  // O(N)
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int max_profits = 0;
    for (int i = 1; i < (int)prices.size(); ++i) {
        max_profits += max(0, prices[i] - prices[i-1]);
    }
    return max_profits;
}

int main() {
    vector<int> prices1{7,1,5,3,6,4};  // ans = 7
    cout << "Case 1 : " << maxProfit(2,prices1) << "\n";

    vector<int> prices2{1,2,3,4,5};  // ans = 4
    cout << "Case 2 : " << maxProfit(2, prices2) << "\n";

    vector<int> prices3{7,6,4,3,1};  // ans = 0
    cout << "Case 3 : " << maxProfit(2, prices3) << "\n";

    return 0;
}