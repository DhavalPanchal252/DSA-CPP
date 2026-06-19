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
    Construct Binary Tree from
    Inorder + Postorder

    Reverse Postorder Indexing (Your Method)

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

Node* helper(vector<int>& inorder,
             vector<int>& postorder,
             unordered_map<int, int>& mapp,
             int inStart,
             int inEnd,
             int postStart,
             int postEnd) {

    if (inStart > inEnd || postStart < postEnd)
        return nullptr;

    Node* root = new Node(postorder[postStart]);

    int inRoot = mapp[root->data];

    int numsRight = inEnd - inRoot;

    root->left = helper(inorder,
                        postorder,
                        mapp,
                        inStart,
                        inRoot - 1,
                        postStart - numsRight - 1,
                        postEnd);

    root->right = helper(inorder,
                         postorder,
                         mapp,
                         inRoot + 1,
                         inEnd,
                         postStart - 1,
                         postStart - numsRight);

    return root;
}

Node* buildTree(vector<int>& inorder,
                vector<int>& postorder) {

    unordered_map<int, int> mapp;

    int n = inorder.size();

    for (int i = 0; i < n; i++)
        mapp[inorder[i]] = i;

    return helper(inorder,
                  postorder,
                  mapp,
                  0,
                  n - 1,
                  n - 1, // postStart -> end
                  0);
}

void preorderTraversal(Node* root) {

    if (!root)
        return;

    cout << root->data << " ";

    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {

    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};

    Node* root = buildTree(inorder, postorder);

    cout << "Preorder Traversal:\n";
    preorderTraversal(root);

    return 0;
}