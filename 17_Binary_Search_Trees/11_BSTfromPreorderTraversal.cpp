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

/*==================================================
    METHOD 1: BST Property + Bound

    TC: O(n)
    SC: O(h)

    Most Optimal Solution
==================================================*/

Node* buildBST_Bound(vector<int>& preorder,
                     int& i,
                     int bound) {

    if (i == preorder.size() ||
        preorder[i] > bound)
        return nullptr;

    Node* root = new Node(preorder[i++]);

    root->left =
        buildBST_Bound(preorder,
                       i,
                       root->data);

    root->right =
        buildBST_Bound(preorder,
                       i,
                       bound);

    return root;
}

Node* bstFromPreorder_Method1(vector<int>& preorder) {

    int i = 0;

    return buildBST_Bound(preorder,
                          i,
                          INT_MAX);
}

/*==================================================
    METHOD 2: Preorder + Inorder Construction

    Steps:
    1. Create inorder by sorting preorder
    2. Build tree using Preorder + Inorder

    TC: O(n log n)
    SC: O(n)
==================================================*/

Node* buildTree(vector<int>& inorder,
                vector<int>& preorder,
                int inStart,
                int inEnd,
                int preStart,
                int preEnd,
                unordered_map<int, int>& mapp) {

    if (inStart > inEnd ||
        preStart > preEnd)
        return nullptr;

    Node* root =
        new Node(preorder[preStart]);

    int inRoot =
        mapp[root->data];

    int numsLeft =
        inRoot - inStart;

    root->left =
        buildTree(inorder,
                  preorder,
                  inStart,
                  inRoot - 1,
                  preStart + 1,
                  preStart + numsLeft,
                  mapp);

    root->right =
        buildTree(inorder,
                  preorder,
                  inRoot + 1,
                  inEnd,
                  preStart + numsLeft + 1,
                  preEnd,
                  mapp);

    return root;
}

Node* bstFromPreorder_Method2(vector<int>& preorder) {

    int n = preorder.size();

    vector<int> inorder = preorder;

    sort(inorder.begin(),
         inorder.end());

    unordered_map<int, int> mapp;

    for (int i = 0; i < n; i++) {
        mapp[inorder[i]] = i;
    }

    return buildTree(inorder,
                     preorder,
                     0,
                     n - 1,
                     0,
                     n - 1,
                     mapp);
}

/*==================================================
    Inorder Traversal
==================================================*/

void inorderTraversal(Node* root) {

    if (!root)
        return;

    inorderTraversal(root->left);

    cout << root->data << " ";

    inorderTraversal(root->right);
}

int main() {

    /*
        Preorder:
        8 5 1 7 10 12

        BST:
                8
              /   \
             5     10
            / \      \
           1   7      12
    */

    vector<int> preorder =
        {8, 5, 1, 7, 10, 12};

    Node* root1 =
        bstFromPreorder_Method1(preorder);

    Node* root2 =
        bstFromPreorder_Method2(preorder);

    cout << "Method 1 (Bound): ";
    inorderTraversal(root1);
    cout << endl;

    cout << "Method 2 (Preorder + Inorder): ";
    inorderTraversal(root2);
    cout << endl;

    return 0;
}