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
    Function: bottomView

    Time Complexity: O(n log n)
    - Each node is visited once.
    - Map operations take O(log n).

    Space Complexity: O(n)
    - Queue + Map store at most n nodes.
*/

vector<int> bottomView(Node* root) {

    vector<int> ans;

    if (root == nullptr)
        return ans;

    queue<pair<Node*, int>> q;

    // horizontal distance -> node value
    map<int, int> mapp;

    q.push({root, 0});

    while (!q.empty()) {

        auto curr = q.front();
        q.pop();

        Node* node = curr.first;
        int hd = curr.second;

        // Keep updating so the last node
        // encountered at each horizontal distance remains
        mapp[hd] = node->data;

        if (node->left)
            q.push({node->left, hd - 1});

        if (node->right)
            q.push({node->right, hd + 1});
    }

    for (auto &it : mapp)
        ans.push_back(it.second);

    return ans;
}

int main() {

    /*
                1
              /   \
             2     3
            / \   / \
           4   5 6   7

        Bottom View:
        4 2 6 3 7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = bottomView(root);

    cout << "Bottom View: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}