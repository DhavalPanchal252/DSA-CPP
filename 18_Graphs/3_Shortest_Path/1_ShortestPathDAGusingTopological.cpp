#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Shortest Path in DAG

    (Topological Sort + Relaxation)

--------------------------------------------------

    Applicable:

    Directed Acyclic Graph (DAG)

--------------------------------------------------

    Idea:

    1. Perform Topological Sort using DFS.
    2. Store vertices in a stack.
    3. Initialize distance of source
       (node 0) as 0.
    4. Process nodes in Topological Order.
    5. Relax all outgoing edges.

--------------------------------------------------

    Why Topological Order?

    When a node is processed,
    all its predecessors have
    already been processed.

    Therefore, every edge is
    relaxed exactly once.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V + E)

==================================================
*/

// DFS for Topological Sort
void dfs(int u,
         vector<pair<int,int>> adj[],
         vector<int>& vis,
         stack<int>& st) {

    vis[u] = 1;

    for (auto &it : adj[u]) {

        int v = it.first;

        if (!vis[v]) {

            dfs(v, adj, vis, st);
        }
    }

    st.push(u);
}

// Shortest Path in DAG
vector<int> shortestPath(int V,
                         int E,
                         vector<vector<int>>& edges) {

    vector<pair<int,int>> adj[V];

    // Build Adjacency List
    for (int i = 0; i < E; i++) {

        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adj[u].push_back({v, w});
    }

    // Topological Sort
    vector<int> vis(V, 0);
    stack<int> st;

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            dfs(i, adj, vis, st);
        }
    }

    // Distance Array
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    // Relax Edges
    while (!st.empty()) {

        int u = st.top();
        st.pop();

        if (dist[u] != INT_MAX) {

            for (auto &it : adj[u]) {

                int v = it.first;
                int w = it.second;

                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    // Mark Unreachable Nodes
    for (int i = 0; i < V; i++) {

        if (dist[i] == INT_MAX)
            dist[i] = -1;
    }

    return dist;
}

int main() {

    /*
            DAG

                0
              /   \
           (2)     (1)
            /       \
           1 -----> 2
            \       /
           (3)   (6)
              \ /
               3
               |
             (1)
               |
               4
               |
             (2)
               |
               5

        Edges

        0 -> 1 (2)
        0 -> 2 (1)
        1 -> 3 (3)
        2 -> 3 (6)
        3 -> 4 (1)
        4 -> 5 (2)

        Shortest Distance from 0

        0 : 0
        1 : 2
        2 : 1
        3 : 5
        4 : 6
        5 : 8
    */

    int V = 6;
    int E = 6;

    vector<vector<int>> edges = {

        {0,1,2},
        {0,2,1},
        {1,3,3},
        {2,3,6},
        {3,4,1},
        {4,5,2}
    };

    vector<int> dist = shortestPath(V, E, edges);

    cout << "Shortest Distance from Node 0:\n";

    for (int i = 0; i < V; i++) {

        cout << i << " : " << dist[i] << endl;
    }

    return 0;
}