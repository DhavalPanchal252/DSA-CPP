#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

/*
    Function: findCeil

    Finds the Ceil of X in a BST.

    Ceil:
    Smallest value >= X

    Time Complexity: O(h)
    - Traverse one path in BST.

    Space Complexity: O(1)

    h = Height of BST
*/

int findCeil(Node* root, int x) {

    int ceilValue = -1;

    while (root) {

        // Exact match found
        if (root->data == x) {
            ceilValue = root->data;
            return ceilValue;
        }

        // Move right
        if (x > root->data) {
            root = root->right;
        }
        else {
            // Possible ceil
            ceilValue = root->data;
            root = root->left;
        }
    }

    return ceilValue;
}

int main() {

    /*
                8
              /   \
             4     12
            / \    / \
           2   6  10 14

        X = 11

        Ceil = 12
    */

    Node* root = new Node(8);

    root->left = new Node(4);
    root->right = new Node(12);

    root->left->left = new Node(2);
    root->left->right = new Node(6);

    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int x = 11;

    cout << "Ceil of " << x << " = "
         << findCeil(root, x);

    return 0;
}