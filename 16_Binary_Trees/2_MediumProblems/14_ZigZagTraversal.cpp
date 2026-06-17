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
    Function: zigzagLevelOrder

    Time Complexity: O(n)
    - Each node is visited exactly once.

    Space Complexity: O(n)
    - Queue stores nodes level by level.
    - Answer vector also stores all nodes.
*/


// Method 1 : Using reverse()

/*
    TC: O(n)
    SC: O(n)
*/
vector<vector<int>> zigzagLevelOrder1(Node* root) {

    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {

        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {

            Node* node = q.front();
            q.pop();

            level.push_back(node->data);

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        if (!leftToRight)
            reverse(level.begin(), level.end());

        ans.push_back(level);

        leftToRight = !leftToRight;
    }

    return ans;
}

// Method 2 : Without reverse()

/*
    TC: O(n)
    SC: O(n)
*/
vector<vector<int>> zigzagLevelOrder(Node* root) {

    vector<vector<int>> ans;

    if (root == nullptr)
        return ans;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {

        int size = q.size();

        vector<int> level(size);

        for (int i = 0; i < size; i++) {

            Node* node = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;

            level[index] = node->data;

            if (node->left)
                q.push(node->left);

            if (node->right)
                q.push(node->right);
        }

        ans.push_back(level);

        leftToRight = !leftToRight;
    }

    return ans;
}
int main() {

    /*
              1
            /   \
           2     3
          / \   / \
         4   5 6   7

        Zigzag Traversal:
        1
        3 2
        4 5 6 7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> ans = zigzagLevelOrder1(root);
    // vector<vector<int>> ans = zigzagLevelOrder2(root);

    for (auto level : ans) {
        for (int x : level)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}