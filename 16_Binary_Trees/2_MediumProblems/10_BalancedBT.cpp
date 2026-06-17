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
    Function: isBalanced

    Time Complexity: O(n)
    - Each node is visited only once.

    Space Complexity: O(h)
    - h = height of the tree (recursion stack).
    - Best Case (Balanced Tree): O(log n)
    - Worst Case (Skewed Tree): O(n)
*/

int helper(Node* root) {

    if (root == nullptr)
        return 0;

    int leftH = helper(root->left);

    // Left subtree is unbalanced
    if (leftH == -1)
        return -1;

    int rightH = helper(root->right);

    // Right subtree is unbalanced
    if (rightH == -1)
        return -1;

    // Current node is unbalanced
    if (abs(leftH - rightH) > 1)
        return -1;

    return 1 + max(leftH, rightH);
}

bool isBalanced(Node* root) {
    return helper(root) != -1;
}

int main() {

    /*
            1
           / \
          2   3
         / \
        4   5
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isBalanced(root))
        cout << "Tree is Balanced";
    else
        cout << "Tree is Not Balanced";

    return 0;
}