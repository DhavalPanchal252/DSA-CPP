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
    Function: amountOfTime

    Time Complexity: O(n)
    - Parent mapping takes O(n).
    - BFS traversal takes O(n).

    Space Complexity: O(n)
    - Parent map
    - Visited map
    - Queue

    Idea:
    1. Build parent mapping.
    2. Find the starting infected node.
    3. Perform BFS from the start node.
    4. Infection spreads to:
       - Left Child
       - Right Child
       - Parent
    5. Each BFS level represents 1 minute.
*/

void makeParent(Node* root,
                unordered_map<Node*, Node*>& parent,
                Node*& startNode,
                int start) {

    if (root == nullptr)
        return;

    if (root->data == start)
        startNode = root;

    if (root->left)
        parent[root->left] = root;

    if (root->right)
        parent[root->right] = root;

    makeParent(root->left, parent, startNode, start);
    makeParent(root->right, parent, startNode, start);
}

int amountOfTime(Node* root, int start) {

    unordered_map<Node*, Node*> parent;

    Node* startNode = nullptr;

    makeParent(root, parent, startNode, start);

    queue<Node*> q;

    unordered_map<Node*, bool> visited;

    q.push(startNode);
    visited[startNode] = true;

    int time = 0;

    while (!q.empty()) {

        int size = q.size();

        bool burned = false;

        for (int i = 0; i < size; i++) {

            Node* node = q.front();
            q.pop();

            // Left Child
            if (node->left && !visited[node->left]) {

                q.push(node->left);
                visited[node->left] = true;
                burned = true;
            }

            // Right Child
            if (node->right && !visited[node->right]) {

                q.push(node->right);
                visited[node->right] = true;
                burned = true;
            }

            // Parent
            if (parent[node] && !visited[parent[node]]) {

                q.push(parent[node]);
                visited[parent[node]] = true;
                burned = true;
            }
        }

        // Infection spread during this minute
        if (burned)
            time++;
    }

    return time;
}

int main() {

    /*
                1
              /   \
             5     3
            / \   / \
           4   10 6  9
              / \
             2   7

        Start = 3

        Infection Spread:
        Minute 0 : 3
        Minute 1 : 1,6,9
        Minute 2 : 5
        Minute 3 : 4,10
        Minute 4 : 2,7

        Answer = 4
    */

    Node* root = new Node(1);

    root->left = new Node(5);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(10);

    root->right->left = new Node(6);
    root->right->right = new Node(9);

    root->left->right->left = new Node(2);
    root->left->right->right = new Node(7);

    int start = 3;

    cout << "Time Required to Infect Tree: "
         << amountOfTime(root, start);

    return 0;
}