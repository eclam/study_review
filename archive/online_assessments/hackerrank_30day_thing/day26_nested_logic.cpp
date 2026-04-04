#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    // INPUT
    int return_day, return_month, return_year, due_day, due_month, due_year;

    cin >> return_day;
    cin >> return_month;
    cin >> return_year;

    cin >> due_day;
    cin >> due_month;
    cin >> due_year;

    int fine = 0;

    if (return_year > due_year) {
        fine = 10000;
    } else if (return_year == due_year) {
        if (return_month > due_month) {
            fine = (return_month - due_month) * 500;
        } else if (return_month == due_month) {
            if (return_day > due_day) {
                fine = (return_day - due_day) * 15;
            }
        }
    }
    cout << fine << "\n";
    return 0;
}
