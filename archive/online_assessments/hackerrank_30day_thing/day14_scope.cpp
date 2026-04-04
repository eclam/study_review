#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Difference {
private:
    vector<int> elements;

public:
    int maximumDifference;

    Difference(vector<int> given_elements) { elements = given_elements; }

    void computeDifference() {
        int vect_size = elements.size();
        if (vect_size > 0) {
            int max_val = elements[0];
            int min_val = elements[0];
            for (int i = 0; i < vect_size; ++i) {
                max_val = max(max_val, elements[i]);
                min_val = min(min_val, elements[i]);
            }
            maximumDifference = abs(max_val - min_val);
        }
        
    }

};  // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}