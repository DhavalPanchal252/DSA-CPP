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
    Function: countNodes

    Optimized for Complete Binary Tree

    Time Complexity: O(log² n)
    - At each node, left and right heights
      are computed in O(log n).
    - Recursive calls occur for O(log n) levels.

    Space Complexity: O(log n)
    - Recursive stack height.
*/

/* Left Height */
int leftHeight(Node* root) {

    int height = 0;

    while (root) {
        height++;
        root = root->left;
    }

    return height;
}

/* Right Height */
int rightHeight(Node* root) {

    int height = 0;

    while (root) {
        height++;
        root = root->right;
    }

    return height;
}

int countNodes(Node* root) {

    if (root == nullptr)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    // Perfect Binary Tree
    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main() {

    /*
                1
              /   \
             2     3
            / \   /
           4   5 6

        Total Nodes = 6
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);

    cout << "Total Nodes: "
         << countNodes(root);

    return 0;
}