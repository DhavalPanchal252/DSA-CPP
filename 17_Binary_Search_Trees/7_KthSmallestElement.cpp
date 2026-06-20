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
=========================================
Method 1: Recursive Inorder Traversal

TC: O(n)
SC: O(h)
=========================================
*/

void helper(Node* root, int &k, int &ans) {

    if (!root)
        return;

    helper(root->left, k, ans);

    if (--k == 0) {
        ans = root->data;
        return;
    }

    helper(root->right, k, ans);
}

int kthSmallestRecursive(Node* root, int k) {

    int ans = -1;

    helper(root, k, ans);

    return ans;
}

/*
=========================================
Method 2: Morris Traversal

TC: O(n)
SC: O(1)
=========================================
*/

int kthSmallestMorris(Node* root, int k) {

    int ans = -1;

    while (root) {

        if (!root->left) {

            if (--k == 0)
                ans = root->data;

            root = root->right;
        }
        else {

            Node* prev = root->left;

            while (prev->right &&
                   prev->right != root) {
                prev = prev->right;
            }

            if (!prev->right) {

                prev->right = root;
                root = root->left;
            }
            else {

                prev->right = nullptr;

                if (--k == 0)
                    ans = root->data;

                root = root->right;
            }
        }
    }

    return ans;
}

int main() {

    /*
                5
              /   \
             3     6
            / \
           2   4
          /
         1

        Inorder:
        1 2 3 4 5 6

        k = 3
        Answer = 3
    */

    Node* root = new Node(5);

    root->left = new Node(3);
    root->right = new Node(6);

    root->left->left = new Node(2);
    root->left->right = new Node(4);

    root->left->left->left = new Node(1);

    int k = 3;

    cout << "Recursive Method : "
         << kthSmallestRecursive(root, k)
         << endl;

    cout << "Morris Method    : "
         << kthSmallestMorris(root, k)
         << endl;

    return 0;
}