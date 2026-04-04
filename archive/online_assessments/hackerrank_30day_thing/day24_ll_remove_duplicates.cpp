#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node *next;
    Node(int d) {
        data = d;
        next = NULL;
    }
};
class Solution {
public:
    // Since non-decreasing order, no need to do std::map
    Node *removeDuplicates(Node *head) {
        // Write your code here
        Node *temp_prev = head;
        int data_prev   = head->data;
        Node *temp      = head->next;
        while (temp != NULL) {
            if (data_prev == temp->data) {
                temp_prev->next = temp->next;
                free(temp);
                temp = temp_prev->next;
            }
            else {
                temp_prev = temp;
                data_prev = temp->data;
                temp      = temp->next;
            }
        }
        return head;
    }

    Node *insert(Node *head, int data) {
        Node *p = new Node(data);
        if (head == NULL) {
            head = p;

        } else if (head->next == NULL) {
            head->next = p;

        } else {
            Node *start = head;
            while (start->next != NULL) {
                start = start->next;
            }
            start->next = p;
        }
        return head;
    }
    void display(Node *head) {
        Node *start = head;
        while (start) {
            cout << start->data << " ";
            start = start->next;
        }
    }
};

int main() {
    Node *head = NULL;
    Solution mylist;
    int T, data;
    cin >> T;
    while (T-- > 0) {
        cin >> data;
        head = mylist.insert(head, data);
    }
    head = mylist.removeDuplicates(head);

    mylist.display(head);
}