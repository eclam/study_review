// Problem Taken from:
//      https://leetcode.com/problems/longest-well-performing-interval/
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;

int longestWPI_iters(vector<int>& hours) {  // Using Iterators -> too slow (fastest time was 32ms)
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    unordered_map<int, int> pre_img;
    unordered_map<int, int>::iterator map_iter;

    auto net_val = 0;
    auto max_WPI = 0;
    auto idx_num = 0;

    auto hour_expr = [](int val) {if (val > 8) return 1;return -1; };
    for (auto idx = hours.begin(); idx != hours.end(); ++idx) {
        idx_num = distance(hours.begin(), idx);

        net_val += hour_expr(*idx);
        max_WPI = (net_val > 0) ? (idx_num + 1) : max_WPI;

        pre_img.insert(pre_img.begin(), pair<int, int>(net_val, idx_num));  // checks automatically if net_val exists in map
        map_iter = pre_img.find(net_val - 1);
        max_WPI  = (map_iter != pre_img.end()) ? max(max_WPI, (idx_num - map_iter->second)) : max_WPI;
    }

    return max_WPI;
}

int longestWPI(vector<int>& hours) {  // Using indexes -> 20ms
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    auto n       = hours.size();
    auto net_val = 0;
    auto max_WPI = 0;

    unordered_map<int, int> pre_img;
    pre_img.reserve(n);

    for (int idx = 0; idx < n; ++idx) {
        net_val += (hours[idx] > 8) ? 1 : -1;
        max_WPI = (net_val > 0) ? idx + 1 : max_WPI;
        if (net_val <= 0) {
            if (pre_img.find(net_val) == pre_img.end()) {
                pre_img[net_val] = idx;
            }
            max_WPI = (pre_img.find(net_val - 1) != pre_img.end()) ? max(max_WPI, idx - pre_img[net_val - 1]) : max_WPI;
        }
    }

    return max_WPI;
}

int main() {
    vector<int> hours{9, 9, 6, 0, 6, 9};
    cout << "Case {9, 9, 6, 0, 6, 9}: " << longestWPI(hours) << "\n";

    vector<int> hours1{6, 9, 9};
    cout << "Case {6, 9, 9}: " << longestWPI(hours1) << "\n";
}