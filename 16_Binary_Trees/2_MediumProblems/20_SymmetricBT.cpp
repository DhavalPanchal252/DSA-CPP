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
    Function: isSymmetric

    Time Complexity: O(n)
    - Every node is visited once.

    Space Complexity: O(h)
    - Recursion stack.
    - h = height of tree.
*/

bool helper(Node* p, Node* q) {

    // If either is NULL, both must be NULL
    if (p == nullptr || q == nullptr)
        return p == q;

    return (p->data == q->data) &&
           helper(p->left, q->right) &&
           helper(p->right, q->left);
}

bool isSymmetric(Node* root) {

    if (root == nullptr)
        return true;

    return helper(root->left, root->right);
}

int main() {

    /*
                1
              /   \
             2     2
            / \   / \
           3   4 4   3

        Symmetric Tree
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if (isSymmetric(root))
        cout << "Tree is Symmetric";
    else
        cout << "Tree is Not Symmetric";

    return 0;
}