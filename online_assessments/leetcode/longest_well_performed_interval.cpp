// Problem Taken from:
//      https://leetcode.com/problems/longest-well-performing-interval/
#include <iostream>
#include <vector>
using namespace std;

int longestWPI(vector<int>& hours) {

}

int main() {
    vector<int> hours{9, 9, 6, 6, 6, 9};
    cout << "Case {9, 9, 6, 6, 6, 9}: " << longestWPI(hours) << "\n";

    vector<int> hours{6, 6, 9};
    cout << "Case {6, 9, 9}: " << longestWPI(hours) << "\n";
}