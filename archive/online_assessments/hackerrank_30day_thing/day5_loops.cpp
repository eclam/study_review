// Problem Taken from:
//
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    for (int i = 1; i <= 10; ++i) {
        cout << n << " x " << i << " = " << i*n << "\n";
    }

    return 0;
}