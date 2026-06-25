#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Depth First Search (DFS)

    DFS Traversal:
    - Uses Recursion (or Stack)
    - Goes as deep as possible before backtracking

    Steps:
    1. Start from source node (0)
    2. Mark it visited
    3. Add it to answer
    4. Visit all unvisited neighbors recursively

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)
    + O(V) Recursion Stack (Worst Case)

==================================================
*/

void dfsTraversal(int u,
                  vector<int>& vis,
                  vector<int>& ans,
                  vector<vector<int>>& adj) {

    vis[u] = 1;

    ans.push_back(u);

    for (auto& v : adj[u]) { // 2E

        if (!vis[v]) {

            dfsTraversal(v, vis, ans, adj);
        }
    }
}

vector<int> dfs(vector<vector<int>>& adj) {

    vector<int> vis(adj.size(), 0);

    vector<int> ans;

    dfsTraversal(0, vis, ans, adj);

    return ans;
}

int main() {

    /*
            Graph

                0
              /   \
             1     2
            / \     \
           3   4     5

        Adjacency List:

        0 -> 1 2
        1 -> 0 3 4
        2 -> 0 5
        3 -> 1
        4 -> 1
        5 -> 2

        DFS Traversal:
        0 1 3 4 2 5
    */

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);   // Undirected Graph
    }

    vector<int> ans = dfs(adj);

    cout << "DFS Traversal: ";

    for (auto node : ans) {

        cout << node << " ";
    }

    cout << endl;

    return 0;
}