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
    Method 1: Inorder + Two Pointer

    1. Store BST inorder traversal
    2. Apply Two Pointer

    TC: O(n)
    SC: O(n)
==================================================
*/

void findInorder(Node* root, vector<int>& inorder) {

    if (root == nullptr)
        return;

    findInorder(root->left, inorder);

    inorder.push_back(root->data);

    findInorder(root->right, inorder);
}

bool findTarget(Node* root, int k) {

    vector<int> inorder;

    findInorder(root, inorder);

    int l = 0;
    int r = inorder.size() - 1;

    while (l < r) {

        int sum = inorder[l] + inorder[r];

        if (sum < k)
            l++;

        else if (sum > k)
            r--;

        else
            return true;
    }

    return false;
}

int main() {

    /*
                5
              /   \
             3     6
            / \     \
           2   4     7

        Target = 9

        2 + 7 = 9
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->right = new Node(7);

    int k = 9;

    if (findTarget(root, k))
        cout << "True";
    else
        cout << "False";

    return 0;
}