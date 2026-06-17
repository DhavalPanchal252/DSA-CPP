#include <bits/stdc++.h>
using namespace std;
/*The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.*/
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
    Function: diameterOfBinaryTree

    Time Complexity: O(n)
    - Each node is visited exactly once.

    Space Complexity: O(h)
    - h = height of the tree (recursion stack).
    - Best Case (Balanced Tree): O(log n)
    - Worst Case (Skewed Tree): O(n)
*/

int helper(Node* root, int &diameter) {

    if (root == nullptr)
        return 0;

    int leftH = helper(root->left, diameter);
    int rightH = helper(root->right, diameter);

    // Update diameter
    diameter = max(diameter, leftH + rightH);

    // Return height of current subtree
    return 1 + max(leftH, rightH);
}

int diameterOfBinaryTree(Node* root) {

    int diameter = 0;
    helper(root, diameter);

    return diameter;
}

int main() {

    /*
              1
             / \
            2   3
           / \
          4   5

        Diameter = 3
        Path: 4 -> 2 -> 1 -> 3
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Diameter of Binary Tree: "
         << diameterOfBinaryTree(root);

    return 0;
}