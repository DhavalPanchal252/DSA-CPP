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
    Function: maxDepth

    Time Complexity: O(n)
    - Every node is visited exactly once.

    Space Complexity: O(h)
    - h = height of the tree (recursion stack space).
    - Best Case (Balanced Tree): O(log n)
    - Worst Case (Skewed Tree): O(n)
*/
int maxDepth(Node* root) {

    // Base Case
    if (root == nullptr)
        return 0;

    return 1 + max(maxDepth(root->left),
                   maxDepth(root->right));
}

int main() {
    /*
            1
          /   \
         2     3
        / \   / \
       4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Maximum Depth: " << maxDepth(root);

    return 0;
}