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
    Function: buildTree

    Construct Binary Tree from:
    - Preorder Traversal
    - Inorder Traversal

    Time Complexity: O(n)
    - Every node is created once.
    - Hash map lookup takes O(1).

    Space Complexity: O(n)
    - Hash map stores inorder indices.
    - Recursion stack O(h).
*/

Node* helper(vector<int>& preorder,
             vector<int>& inorder,
             unordered_map<int, int>& mapp,
             int inStart,
             int inEnd,
             int preStart,
             int preEnd) {

    if (inStart > inEnd || preStart > preEnd)
        return nullptr;

    // First element of preorder is root
    Node* root = new Node(preorder[preStart]);

    // Root position in inorder
    int inRoot = mapp[root->data];

    // Number of nodes in left subtree
    int numsLeft = inRoot - inStart;

    root->left = helper(preorder,
                        inorder,
                        mapp,
                        inStart,
                        inRoot - 1,
                        preStart + 1,
                        preStart + numsLeft);

    root->right = helper(preorder,
                         inorder,
                         mapp,
                         inRoot + 1,
                         inEnd,
                         preStart + numsLeft + 1,
                         preEnd);

    return root;
}

Node* buildTree(vector<int>& preorder,
                vector<int>& inorder) {

    unordered_map<int, int> mapp;

    int n = inorder.size();

    for (int i = 0; i < n; i++) {
        mapp[inorder[i]] = i;
    }

    return helper(preorder,
                  inorder,
                  mapp,
                  0,
                  n - 1,
                  0,
                  n - 1);
}

/* Inorder Traversal */
void inorderTraversal(Node* root) {

    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {

    /*
            Tree:

                3
              /   \
             9     20
                  /  \
                 15   7

        Preorder:
        3 9 20 15 7

        Inorder:
        9 3 15 20 7
    */

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Node* root = buildTree(preorder, inorder);

    cout << "Inorder Traversal of Constructed Tree:\n";

    inorderTraversal(root);

    return 0;
}