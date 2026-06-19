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
    Function: distanceK

    Time Complexity: O(n)
    - Build parent mapping: O(n)
    - BFS traversal: O(n)

    Space Complexity: O(n)
    - Parent map
    - Visited map
    - Queue

    Idea:
    1. Store parent of every node.
    2. Treat tree as an undirected graph.
    3. Start BFS from target node.
    4. Move to:
       - left child
       - right child
       - parent
    5. Stop when distance becomes k.
*/

void makeParent(Node* root, unordered_map<Node*, Node*>& parent) {

    if (root == nullptr)
        return;

    if (root->left)
        parent[root->left] = root;

    if (root->right)
        parent[root->right] = root;

    makeParent(root->left, parent);
    makeParent(root->right, parent);
}

vector<int> distanceK(Node* root, Node* target, int k) {

    vector<int> result;

    if (root == nullptr)
        return result;

    unordered_map<Node*, Node*> parent;

    makeParent(root, parent);

    unordered_map<Node*, bool> visited;

    queue<Node*> q;

    q.push(target);
    visited[target] = true;

    int currLevel = 0;

    while (!q.empty()) {

        int size = q.size();

        if (currLevel == k)
            break;

        currLevel++;

        for (int i = 0; i < size; i++) {

            Node* curr = q.front();
            q.pop();

            // Left Child
            if (curr->left &&
                !visited[curr->left]) {

                q.push(curr->left);
                visited[curr->left] = true;
            }

            // Right Child
            if (curr->right &&
                !visited[curr->right]) {

                q.push(curr->right);
                visited[curr->right] = true;
            }

            // Parent
            if (parent[curr] &&
                !visited[parent[curr]]) {

                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
    }

    while (!q.empty()) {

        result.push_back(q.front()->data);
        q.pop();
    }

    return result;
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

        Target = 5
        K = 2

        Answer:
        7 4 1
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

    Node* target = root->left; // Node 5

    int k = 2;

    vector<int> ans = distanceK(root, target, k);

    cout << "Nodes at Distance " << k << ": ";

    for (int x : ans)
        cout << x << " ";

    return 0;
}