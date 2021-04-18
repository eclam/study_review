// Problem Taken from:
//      https://leetcode.com/problems/longest-well-performing-interval/
#include <iostream>
#include <vector>
using namespace std;

int longestWPI(vector<int>& hours) {
    vector<int> day_prefix_sum;
    day_prefix_sum.push_back(0);

    auto hour_expr = [](int val) {if (val > 8) return 1;return -1; };
    for (auto idx = hours.begin(); idx != hours.end(); ++idx) {         // make prefix sums
        day_prefix_sum.push_back(day_prefix_sum[day_prefix_sum.size() - 1] + hour_expr(*idx));
    }

    cout << "DAY PREFIX SUM  : { ";
    for (auto& i : day_prefix_sum) {
        cout << i << " ";
    }
    cout << "}\n";

    vector<int> day_stack;
    for (int i = 0; i <= hours.size(); i++) {
        if (day_stack.empty() || day_prefix_sum[day_stack[day_stack.size() - 1]] > day_prefix_sum[i]) {
            if (!day_stack.empty()) {
                auto temp = day_prefix_sum[day_stack[day_stack.size() - 1]];
                cout << "\ni : " << i << "\n"
                     << " | Day Stack End iter : " << day_stack[day_stack.size() - 1]
                     << " | day_prefix_sum[j] : " << temp
                     << " | day_prefix_sum[i] : " << day_prefix_sum[i] << "\n";
            }

            day_stack.push_back(i);
        }
    }

    cout << "DAY STACK  : { ";
    for (auto& i : day_stack) {
        cout << i << " ";
    }
    cout << "}\n";

    auto max_consec_sum_num = 0;
    for (int i = hours.size(); i >= 0; --i) {
        while (!day_stack.empty() && day_prefix_sum[day_stack[day_stack.size() - 1]] < day_prefix_sum[i]) {
            max_consec_sum_num = max(max_consec_sum_num, i - day_stack[day_stack.size() - 1]);
            day_stack.pop_back();
        }
    }


    return max_consec_sum_num;
}

int main() {
    vector<int> hours{9, 9, 6, 0, 6, 9};
    cout << "Case {9, 9, 6, 0, 6, 9}: " << longestWPI(hours) << "\n";

    vector<int> hours1{6, 9, 9};
    cout << "Case {6, 9, 9}: " << longestWPI(hours1) << "\n";
}