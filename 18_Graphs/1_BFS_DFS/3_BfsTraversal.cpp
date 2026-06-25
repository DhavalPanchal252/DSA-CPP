#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Breadth First Search (BFS)

    BFS Traversal:
    - Uses Queue (FIFO)
    - Visits nodes level by level

    Steps:
    1. Start from source node (0)
    2. Mark it visited
    3. Push it into queue
    4. While queue is not empty:
       - Pop front node
       - Add it to answer
       - Visit all unvisited neighbors

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/
vector<int> bfs(vector<vector<int>>& adj) {

    vector<int> ans;
    vector<int> vis(adj.size(), 0);

    queue<int> q;

    q.push(0);
    vis[0] = 1;

    while (!q.empty()) { // V

        int u = q.front();
        q.pop();

        ans.push_back(u);

        for (auto& v : adj[u]) { // degree of nodes : 2E

            if (!vis[v]) {

                vis[v] = 1;
                q.push(v);
            }
        }
    }

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

        BFS Traversal:
        0 1 2 3 4 5
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

    vector<int> ans = bfs(adj);

    for (auto node : ans) {
        cout << node << " ";
    }

    return 0;
}