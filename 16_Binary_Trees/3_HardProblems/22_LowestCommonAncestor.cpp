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
    Function: Lowest Common Ancestor (LCA)

    Time Complexity: O(n)
    - In the worst case, every node is visited once.

    Space Complexity: O(h)
    - Recursion stack.
    - h = height of tree.
    - O(log n) for balanced tree.
    - O(n) for skewed tree.
*/

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {

    // Base Cases
    if (root == nullptr || root == p || root == q)
        return root;

    Node* leftH = lowestCommonAncestor(root->left, p, q);
    Node* rightH = lowestCommonAncestor(root->right, p, q);

    // after returning check left and right child , means if both child has not null values then root is answer , if any one node is null then return not null child

    // p and q are in different subtrees
    if (leftH && rightH)
        return root;

    // Either left subtree or right subtree contains both nodes
    return (leftH == nullptr) ? rightH : leftH;
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

        p = 5
        q = 1

        LCA = 3
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

    Node* p = root->left;   // Node 5
    Node* q = root->right;  // Node 1

    Node* lca = lowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor: "
         << lca->data << endl;

    return 0;
}