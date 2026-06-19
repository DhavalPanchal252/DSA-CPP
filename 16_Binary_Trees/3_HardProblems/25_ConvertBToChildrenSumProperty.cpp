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
    Function: changeTree

    Convert Binary Tree to Children Sum Property

    Time Complexity: O(n)
    - Every node is visited exactly once.

    Space Complexity: O(h)
    - Recursion stack.
    - h = height of tree.

    Idea:
    1. Top-Down:
       If children sum < parent,
       propagate parent value to children.

    2. Bottom-Up:
       After recursion, update parent as
       sum of left and right child.
*/

void changeTree(Node* root) {

    if (root == nullptr)
        return;

    int child = 0;

    if (root->left)
        child += root->left->data;

    if (root->right)
        child += root->right->data;

    // Top-Down Step : if root <= child then update root value
    if (child >= root->data) {
        root->data = child;
    }
    else { // root > child then update both child value as root value

        if (root->left)
            root->left->data = root->data;

        if (root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    // Bottom-Up Step
    int total = 0;

    if (root->left)
        total += root->left->data;

    if (root->right)
        total += root->right->data;

    if (root->left || root->right) // if root is not leaf node then update root value
        root->data = total;
}

// Inorder Traversal
void inorder(Node* root) {

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    /*
                  3
                /   \
               5     1
              / \   / \
             6   2 0   8
                / \
               7   4
    */

    Node* root = new Node(3);

    root->left = new Node(5);
    root->right = new Node(1);

    root->left->left = new Node(6);
    root->left->right = new Node(2);

    root->right->left = new Node(0);
    root->right->right = new Node(8);

    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    cout << "Inorder Before Modification:\n";
    inorder(root);
    cout << endl;

    changeTree(root);

    cout << "\nInorder After Children Sum Property:\n";
    inorder(root);
    cout << endl;

    return 0;
}