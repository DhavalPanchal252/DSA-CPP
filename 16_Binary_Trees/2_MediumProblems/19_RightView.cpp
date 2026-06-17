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
=====================================================
Method 1 : DFS (Right -> Left) : reverse Preorder (root Right Left)
=====================================================

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(h)
- Recursion stack.
- h = height of tree.
- O(log n) for balanced tree.
- O(n) for skewed tree.
*/

void helper(Node* root, vector<int>& ans, int level) {

    if (root == nullptr)
        return;

    // First node encountered at this level
    if (level == ans.size())
        ans.push_back(root->data);

    helper(root->right, ans, level + 1);
    helper(root->left, ans, level + 1);
}

vector<int> rightSideViewDFS(Node* root) {

    vector<int> ans;

    helper(root, ans, 0);

    return ans;
}

/*
=====================================================
Method 2 : BFS (Level Order Traversal)
=====================================================

Time Complexity: O(n)
- Every node is visited exactly once.

Space Complexity: O(n)
- Queue may store an entire level.
*/

vector<int> rightSideViewBFS(Node* root) {

    vector<int> ans;

    if (root == nullptr)
        return ans;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {

        int size = q.size();

        for (int i = 0; i < size; i++) {

            Node* curr = q.front();
            q.pop();

            // Last node of current level
            if (i == size - 1)
                ans.push_back(curr->data);

            if (curr->left)
                q.push(curr->left);

            if (curr->right)
                q.push(curr->right);
        }
    }

    return ans;
}

int main() {

    /*
                1
              /   \
             2     3
              \     \
               5     4

        Right Side View:
        1 3 4
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);
    root->right->right = new Node(4);

    // DFS Method
    vector<int> ans1 = rightSideViewDFS(root);

    cout << "Right Side View (DFS): ";
    for (int x : ans1)
        cout << x << " ";
    cout << endl;

    // BFS Method
    vector<int> ans2 = rightSideViewBFS(root);

    cout << "Right Side View (BFS): ";
    for (int x : ans2)
        cout << x << " ";
    cout << endl;

    return 0;
}