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
    Function: topView

    Time Complexity: O(n log n)
    - Each node is processed once.
    - Map operations take O(log n).

    Space Complexity: O(n)
    - Queue + Map.
*/

vector<int> topView(Node* root) {

    vector<int> ans;

    if (root == nullptr)
        return ans;

    // horizontal distance -> node value
    map<int, int> mapp;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while (!q.empty()) {

        auto curr = q.front();
        q.pop();

        Node* node = curr.first;
        int hd = curr.second;

        // Store first node seen at this horizontal distance
        if (mapp.find(hd) == mapp.end())
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

        Top View:
        4 2 1 3 7
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> ans = topView(root);

    cout << "Top View: ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}