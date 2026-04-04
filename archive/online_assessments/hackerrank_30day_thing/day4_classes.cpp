// Problem Taken from:
//
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Person {
public:
    int age;
    Person(int initialAge);
    void amIOld();
    void yearPasses();
};

Person::Person(int initialAge) {
    // Takes INT, check if intialAge >= 0
    // IF intialAge < 0 => set age = 0 AND print "Age is not valid, setting age to 0."
    if (initialAge < 0) {
        cout << "Age is not valid, setting age to 0.\n";
        age = 0;
    }
    else {
        age = initialAge;
    }
}

void Person::amIOld() {
    // IF age < 13 => print "You are young."
    // IF age >= 13 AND age < 18 => print "You are a teenager."
    // ELSE => print "You are old."
    if (age < 13) {
        cout << "You are young.\n";
    }
    else if (age >= 13 && age < 18) {
        cout << "You are a teenager.\n";
    }
    else {
        cout << "You are old.\n";
    }
}

void Person::yearPasses() {
    age += 1;
}

int main() {
    return 0;
}