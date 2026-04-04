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

int main() {
    int num_of_inputs = 0;
    cin >> num_of_inputs;

    std::map<std::string, std::string> phonebook;

    for (int i = 0; i < num_of_inputs; ++i) {
        string name;
        string phone_number;
        cin >> name;
        cin >> phone_number;
        phonebook[name] = phone_number;
    }

    string find_name;
    while (cin >> find_name) {
        if (phonebook.find(find_name) == phonebook.end()) {
            cout << "Not found\n";
        } else {
            cout << find_name << "=" << phonebook[find_name] << "\n";
        }
    }

    return 0;
}
