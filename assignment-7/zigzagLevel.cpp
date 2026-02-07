#include <bits/stdc++.h>
using namespace std;
// TC :O(n) and SC : O(n)
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int main() {
    int n;
    if(!(cin >> n)) return 0;

    if (n == 0) {
        cout << "[]";
        return 0;
    }

    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // Build tree
    if (arr[0] == "null") {
        cout << "[]";
        return 0;
    }

    TreeNode* root = new TreeNode(stoi(arr[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n) {
        TreeNode* node = q.front();
        q.pop();

        if (i < n && arr[i] != "null") {
            node->left = new TreeNode(stoi(arr[i]));
            q.push(node->left);
        }
        i++;

        if (i < n && arr[i] != "null") {
            node->right = new TreeNode(stoi(arr[i]));
            q.push(node->right);
        }
        i++;
    }

    //clear the queue before zigzag <<<
    while (!q.empty()) q.pop();

    // Zigzag Level Order
    vector<vector<int>> ans;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int sz = q.size();
        vector<int> level(sz);

        for (int j = 0; j < sz; j++) {
            TreeNode* node = q.front();
            q.pop();

            int idx = leftToRight ? j : (sz - 1 - j);
            level[idx] = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(level);
        leftToRight = !leftToRight;
    }


    cout << "[";
    for (int r = 0; r < (int)ans.size(); r++) {
        cout << "[";
        for (int c = 0; c < (int)ans[r].size(); c++) {
            cout << ans[r][c];
            if (c + 1 < (int)ans[r].size()) cout << " ";
        }
        cout << "]";
        if (r + 1 < (int)ans.size()) cout << " ";
    }
    cout << "]";
    return 0;
}
