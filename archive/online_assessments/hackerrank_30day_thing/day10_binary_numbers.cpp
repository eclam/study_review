// Problem Taken from:
//
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

int convert_to_binary(int n) {
    vector<int> remainders;
    while (n > 0) {
        remainders.push_back(n % 2);
        n /= 2;
    }

    int max_count = 0, temp_count = 0;
    for (int i = remainders.size() - 1; i >= 0; --i) {
        if (remainders[i] == 0) {
            temp_count = 0;
        } else {
            temp_count++;
        }
        max_count = max(max_count, temp_count);
    }

    return max_count;
}

int main() {
    int input_num = 13;
    // cin >> input_num;
    cout << convert_to_binary(input_num) << "\n";

    return 0;
}
