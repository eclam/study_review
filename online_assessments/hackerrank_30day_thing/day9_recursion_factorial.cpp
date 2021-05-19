// Problem Taken from:
//
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>
#include <iterator>

using namespace std;

int factorial(int n){
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    int input_num = 0;
    cin >> input_num;

    cout << factorial(input_num) << "\n";

    return 0;
}
