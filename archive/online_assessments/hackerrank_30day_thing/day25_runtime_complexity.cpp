#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void prime_or_not_bruteforce(int n){ // brute force odd num method
    if (n == 3 || n == 2) {
        cout << "Prime\n";
        return;
    } else if (n == 1) {
        cout << "Not prime\n";
        return;
    }
    else if ((n % 2) != 0) {
        bool prime_flag = true;
        for (int i = 3; i < n; i += 2) {
            if (n % i == 0) {
                prime_flag = false;
                break;
            }
        }
        if (prime_flag) {
            cout << "Prime\n";
            return;
        }
    }
    cout << "Not prime\n";
    return;
}



// void prime_or_not(int n){
//     if (n == 1) {
//         cout << "Not prime\n";
//         return;
//     }
//     else if (n <= 3){
//         cout << "Prime\n";
//         return;
//     }

//     int sqrt_n = sqrt(n);
//     for (int i = 2; i <= sqrt_n; ++i) {
//         if (n%i == 0) {
//             cout << "Not prime\n";
//             return;
//         }
//     }
//     cout << "Prime\n";
// }

void prime_or_not(int n) {  // 6k+1 method
    if (n == 1) {
        cout << "Not prime\n";
        return;
    } else if (n <= 3) {
        cout << "Prime\n";
        return;
    } else if (n % 2 == 0 || n % 3 == 0) {
        cout << "Not prime\n";
        return;
    }

    int sqrt_n = sqrt(n);
    for (int i = 5; i <= sqrt(n); i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            cout << "Not prime\n";
            return;
        }
    }
    cout << "Prime\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_inputs, data;
    vector<int> nums_to_process;
    cin >> num_inputs;
    while (num_inputs-- > 0) {
        cin >> data;
        nums_to_process.push_back(data);
    }

    for (int i = 0; i < nums_to_process.size(); ++i) {
        prime_or_not(nums_to_process[i]);
    }
    return 0;
}
