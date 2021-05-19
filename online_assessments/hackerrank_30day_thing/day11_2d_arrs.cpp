// Problem Taken from:
//
#include <bits/stdc++.h>

#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

using namespace std;
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


int main() {
    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int max_sum = INT_MIN;
    int inner_size = arr[0].size();
    for (int i = 1; i < arr.size()-1; ++i) {
        for (int k = 1; k < inner_size-1; ++k) {
            int temp_sum = 0;
            temp_sum += arr[i-1][k-1] + arr[i-1][k] + arr[i-1][k+1]; // TOP PART
            temp_sum += arr[i][k]; // MID PART
            temp_sum += arr[i+1][k-1] + arr[i+1][k] + arr[i+1][k+1]; // BOT PART
            max_sum = max(max_sum, temp_sum);
        }
    }
    cout << max_sum << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end   = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}