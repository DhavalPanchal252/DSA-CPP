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
    Function: findMax

    Time Complexity: O(h)
    - Traverse to the rightmost node.

    Space Complexity: O(1)

    h = Height of BST
*/
int findMax(Node* root) {

    while (root && root->right)
        root = root->right;

    return root->data;
}

/*
    Function: findMin

    Time Complexity: O(h)
    - Traverse to the leftmost node.

    Space Complexity: O(1)

    h = Height of BST
*/
int findMin(Node* root) {

    while (root && root->left)
        root = root->left;

    return root->data;
}

int main() {

    /*
                8
              /   \
             3     10
            / \      \
           1   6      14
              / \     /
             4   7   13

        Minimum = 1
        Maximum = 14
    */

    Node* root = new Node(8);

    root->left = new Node(3);
    root->right = new Node(10);

    root->left->left = new Node(1);
    root->left->right = new Node(6);

    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << "Minimum Element: " << findMin(root) << endl;
    cout << "Maximum Element: " << findMax(root) << endl;

    return 0;
}