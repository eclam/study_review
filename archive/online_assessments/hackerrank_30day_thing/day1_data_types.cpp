#include <iomanip>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    int i    = 4;
    double d = 4.0;
    string s = "HackerRank ";

    // Declare second integer, double, and String variables.
    int first;
    double second;
    string temp;

    cin >> first;
    cin >> second;
    getline(cin >> ws, temp);
    // cin >> temp;

    first += i;
    double d_temp = second + d;
    s.append(temp);

    // Read and save an integer, double, and String to your variables.
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.

    // Print the sum of both integer variables on a new line.
    cout << first << "\n";
    // Print the sum of the double variables on a new line.
    printf("%.1f\n", d_temp);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << s << "\n";
    return 0;