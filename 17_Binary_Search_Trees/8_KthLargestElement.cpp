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
    METHOD 1: Count Nodes + Kth Smallest

    TC: O(n)
    SC: O(h)
==================================================*/

void countNodes(Node* root, int& n) {

    if (!root)
        return;

    countNodes(root->left, n);

    n++;

    countNodes(root->right, n);
}

void inorderKth(Node* root, int& k, int& ans) {

    if (!root)
        return;

    inorderKth(root->left, k, ans);

    if (--k == 0) {
        ans = root->data;
        return;
    }

    inorderKth(root->right, k, ans);
}

int kthLargest_Method1(Node* root, int k) {

    int totalNodes = 0;

    countNodes(root, totalNodes);

    int target = totalNodes - k + 1;

    int ans = -1;

    inorderKth(root, target, ans);

    return ans;
}

/*==================================================
    METHOD 2: Reverse Inorder Traversal

    Right -> Root -> Left

    TC: O(h + k)
    SC: O(h)
==================================================*/

void reverseInorder(Node* root, int& k, int& ans) {

    if (!root)
        return;

    reverseInorder(root->right, k, ans);

    if (--k == 0) {
        ans = root->data;
        return;
    }

    reverseInorder(root->left, k, ans);
}

int kthLargest_Method2(Node* root, int k) {

    int ans = -1;

    reverseInorder(root, k, ans);

    return ans;
}

int main() {

    /*
                5
              /   \
             3     7
            / \   / \
           2   4 6   8

        Inorder:
        2 3 4 5 6 7 8

        Reverse Inorder:
        8 7 6 5 4 3 2

        k = 2
        Answer = 7
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(7);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->right->left = new Node(6);
    root->right->right = new Node(8);

    int k = 2;

    cout << "Method 1 (Count Nodes + Inorder) : "
         << kthLargest_Method1(root, k) << endl;

    cout << "Method 2 (Reverse Inorder)       : "
         << kthLargest_Method2(root, k) << endl;

    return 0;
}