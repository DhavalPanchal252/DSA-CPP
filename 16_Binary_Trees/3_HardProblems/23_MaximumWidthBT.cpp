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
    Function: maxWidth

    Time Complexity: O(n)
    - Every node is visited exactly once.

    Space Complexity: O(n)
    - Queue may store an entire level of the tree.

    Idea:
    - Assign indices to nodes as if the tree were stored in an array.
    - Left Child  -> 2*i + 1
    - Right Child -> 2*i + 2
    - Width of a level = lastIndex - firstIndex + 1
*/

int maxWidth(Node* root) {

    if (root == nullptr)
        return 0;

    long long maxi = 0;

    queue<pair<Node*, long long>> q;

    q.push({root, 0});

    while (!q.empty()) {

        int size = q.size();

        long long minIndex = q.front().second;

        long long first, last;

        for (int i = 0; i < size; i++) {

            auto curr = q.front();
            q.pop();

            Node* node = curr.first;

            // Normalize index to avoid overflow
            long long currIndex = curr.second - minIndex;

            if (i == 0) first = currIndex;

            if (i == size - 1) last = currIndex;

            if (node->left) q.push({node->left, currIndex * 2 + 1});

            if (node->right) q.push({node->right, currIndex * 2 + 2});
        }

        maxi = max(maxi, last - first + 1);
    }

    return (int)maxi;
}

int main() {

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7

        Maximum Width = 4
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Maximum Width: "
         << maxWidth(root);

    return 0;
}