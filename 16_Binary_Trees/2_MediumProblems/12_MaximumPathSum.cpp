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
    Function: maxPathSum

    Time Complexity: O(n)
    - Every node is visited once.

    Space Complexity: O(h)
    - h = height of tree (recursion stack).
    - Best Case: O(log n)
    - Worst Case: O(n)
*/

int helper(Node* root, int &maxSum) {

    if (root == nullptr)
        return 0;

    int leftSum = max(0, helper(root->left, maxSum));
    int rightSum = max(0, helper(root->right, maxSum));

    // Path passing through current node
    maxSum = max(maxSum, root->data + leftSum + rightSum);

    // Return best single path to parent
    return root->data + max(leftSum, rightSum);
}

int maxPathSum(Node* root) {

    int maxSum = INT_MIN;

    helper(root, maxSum);

    return maxSum;
}

int main() {

    /*
             -10
             /  \
            9   20
               /  \
              15   7

        Maximum Path Sum = 42
        Path: 15 -> 20 -> 7
    */

    Node* root = new Node(-10);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    cout << "Maximum Path Sum: "
         << maxPathSum(root);

    return 0;
}