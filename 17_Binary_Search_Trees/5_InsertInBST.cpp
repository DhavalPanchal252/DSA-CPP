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
    Function: insertIntoBST

    Insert a node into a BST.

    Time Complexity: O(h)
    - Traverse one path from root to leaf.

    Space Complexity: O(1)

    h = Height of BST
*/

Node* insertIntoBST(Node* root, int val) {

    // If BST is empty
    if (root == nullptr)
        return new Node(val);

    Node* curr = root;

    while (curr) {

        // Move to left subtree
        if (val <= curr->data) {

            if (curr->left) {
                curr = curr->left;
            }
            else {
                curr->left = new Node(val);
                break;
            }
        }

        // Move to right subtree
        else {

            if (curr->right) {
                curr = curr->right;
            }
            else {
                curr->right = new Node(val);
                break;
            }
        }
    }

    return root;
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
                4
              /   \
             2     7
            / \
           1   3

        Insert: 5

                4
              /   \
             2     7
            / \   /
           1   3 5
    */

    Node* root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(7);

    root->left->left = new Node(1);
    root->left->right = new Node(3);

    int val = 5;

    root = insertIntoBST(root, val);

    cout << "Inorder Traversal After Insertion:\n";

    inorder(root);

    return 0;
}