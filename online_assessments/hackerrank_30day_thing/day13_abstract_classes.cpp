#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Book {
protected:
    string title;
    string author;

public:
    Book(string t, string a) {
        title  = t;
        author = a;
    }
    virtual void display() = 0;
};

// Write your MyBook class here

class MyBook : public Book {
protected:
    int price;

public:
    //   Class Constructor
    //
    //   Parameters:
    //   title - The book's title.
    //   author - The book's author.
    //   price - The book's price.
    //
    // Write your constructor here
    MyBook(string title, string author, int price):Book(title, author) {
        this->price  = price;;
    }

    //   Function Name: display
    //   Print the title, author, and price in the specified format.
    //
    // Write your method here
    void display(void) {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Price: " << price << "\n";
    };
};
// End class

int main() {
    string title, author;
    int price;
    getline(cin, title);
    getline(cin, author);
    cin >> price;
    MyBook novel(title, author, price);
    novel.display();
    return 0;
}