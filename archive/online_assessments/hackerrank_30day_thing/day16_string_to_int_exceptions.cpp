#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    getline(cin, S);

    // try {
    //     int num = stoi(S);
    //     cout << num << "\n";
    // }
    // catch (exception e) {
    //     cout << "Bad String\n";
    // }
    
    try {
        int num = stoi(S);
        cout << num << "\n";
    }
    catch (const std::exception& E) {
        cout << "Bad String\n";
    }



    return 0;
}
