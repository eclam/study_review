#include <cstddef>
#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        data  = d;
        left  = NULL;
        right = NULL;
    }
};
class Solution {
public:
    Node* insert(Node* root, int data) {
        if (root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if (data <= root->data) {
                cur        = insert(root->left, data);
                root->left = cur;
            } else {
                cur         = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    int getHeight(Node* root) {
        // Write your code here
        if (root == NULL) {
            return 1;
        }

        int left_side_depth = 0;
        if (root->left != NULL) {
            left_side_depth = getHeight(root->left) + 1;
        }

        int right_side_depth = 0;
        if (root->right != NULL) {
            right_side_depth = getHeight(root->right) + 1;
        }

        int result = (left_side_depth > right_side_depth) ? left_side_depth : right_side_depth;

        return result;
    }

};  // End of Solution

int main() {
    Solution myTree;
    Node* root = NULL;
    int t;
    int data;

    cin >> t;

    while (t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }
    int height = myTree.getHeight(root);
    cout << height;

    return 0;
}