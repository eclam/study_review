// Problem Taken from:
//
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int num_of_inputs = 0;

    cin >> num_of_inputs;

    for (int i = 0; i < num_of_inputs; ++i) {
        string s;
        cin >> s;
        for (int k = 0; k < s.length(); k+=2) {
            cout << s[k];
        }
        cout << " ";
        for (int k = 1; k < s.length(); k += 2) {
            cout << s[k];
        }
        cout << "\n";
    }

    return 0;
}
