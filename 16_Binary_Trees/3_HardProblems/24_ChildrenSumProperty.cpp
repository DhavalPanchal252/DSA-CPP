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
    Function: isSumProperty

    Children Sum Property:
    For every non-leaf node,

        node->data =
        leftChild->data + rightChild->data

    Time Complexity: O(n)
    - Every node is visited once.

    Space Complexity: O(h)
    - Recursion stack.
    - h = height of tree.
*/

bool isSumProperty(Node* root) {

    // Empty tree or leaf node
    if (root == nullptr ||
        (root->left == nullptr &&
         root->right == nullptr))
        return true;

    int leftData = 0;
    int rightData = 0;

    if (root->left)
        leftData = root->left->data;

    if (root->right)
        rightData = root->right->data;

    return (root->data == leftData + rightData) &&
           isSumProperty(root->left) &&
           isSumProperty(root->right);
}

int main() {

    /*
                10
              /    \
             8      2
            / \      \
           3   5      2

        Children Sum Property holds:
        10 = 8 + 2
         8 = 3 + 5
         2 = 0 + 2
    */

    Node* root = new Node(10);

    root->left = new Node(8);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(5);

    root->right->right = new Node(2);

    if (isSumProperty(root))
        cout << "Children Sum Property Satisfied";
    else
        cout << "Children Sum Property Not Satisfied";

    return 0;
}