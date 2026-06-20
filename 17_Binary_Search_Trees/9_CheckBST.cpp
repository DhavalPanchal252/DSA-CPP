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
==================================================
    Method: Range Check

    For every node:
    low < node->data < high

    Left Subtree:
    (low, root->data)

    Right Subtree:
    (root->data, high)

    TC: O(n)
    SC: O(h)
==================================================
*/

bool helper(Node* root, long long low, long long high) {

    if (root == nullptr)
        return true;

    if (root->data <= low || root->data >= high)
        return false;

    return helper(root->left, low, root->data) &&
           helper(root->right, root->data, high);
}

bool isValidBST(Node* root) {

    return helper(root, LLONG_MIN, LLONG_MAX);
}

int main() {

    /*
                5
              /   \
             3     7
            / \   / \
           2   4 6   8

        Valid BST
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    if (isValidBST(root))
        cout << "Valid BST";
    else
        cout << "Invalid BST";

    return 0;
}