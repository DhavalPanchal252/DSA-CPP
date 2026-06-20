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
    Function: deleteNode

    Delete a node from BST

    Cases:
    1. Leaf Node
       -> Delete and return NULL

    2. One Child
       -> Return the child

    3. Two Children
       -> Find Inorder Successor
       -> Copy successor value
       -> Delete successor

    Time Complexity: O(h)
    Space Complexity: O(h)

    h = Height of BST
*/

// Find minimum node in BST
Node* findMin(Node* root) {

    while (root->left)
        root = root->left;

    return root;
}

// Delete node from BST
Node* deleteNode(Node* root, int key) {

    if (root == nullptr)
        return nullptr;

    // Search in left subtree
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }

    // Search in right subtree
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }

    // Node found
    else {

        // No right child
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // No left child
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // Two children
        Node* successor = findMin(root->right);

        root->data = successor->data;

        root->right =
            deleteNode(root->right, successor->data);
    }

    return root;
}

// Inorder Traversal
void inorder(Node* root) {

    if (!root)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {

    /*
                5
              /   \
             3     6
            / \     \
           2   4     7

        Delete: 3

                5
              /   \
             4     6
            /       \
           2         7
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->right = new Node(7);

    cout << "Before Deletion:\n";
    inorder(root);

    root = deleteNode(root, 3);

    cout << "\n\nAfter Deletion:\n";
    inorder(root);

    return 0;
}