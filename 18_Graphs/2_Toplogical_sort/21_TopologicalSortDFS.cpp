#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Topological Sort (DFS + Stack)

    Applicable:
    Directed Acyclic Graph (DAG)

--------------------------------------------------

    Idea:

    1. Perform DFS.
    2. After visiting all neighbours,
       push current node into stack.
    3. Finally pop stack to get
       Topological Order.

--------------------------------------------------

    Why does it work?

    A node is pushed only after all
    nodes reachable from it have
    been processed.

    Therefore:

        u -> v

    u will appear before v in the
    final topological ordering.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)
                       + DFS Stack
                       + Stack

==================================================
*/

void dfs(int u,
         vector<int> adj[],
         vector<int>& vis,
         stack<int>& st) {

    vis[u] = 1;

    for (auto& v : adj[u]) {

        if (!vis[v]) {

            dfs(v, adj, vis, st);
        }
    }

    // Push after visiting all neighbours
    st.push(u);
}

vector<int> topoSort(int V,
                     vector<vector<int>>& edges) {

    vector<int> adj[V];

    // Build adjacency list

    for (auto& edge : edges) {

        int u = edge[0];
        int v = edge[1];

        // u -> v

        adj[u].push_back(v);
    }

    vector<int> vis(V, 0);

    stack<int> st;

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            dfs(i, adj, vis, st);
        }
    }

    vector<int> topo;

    while (!st.empty()) {

        topo.push_back(st.top());
        st.pop();
    }

    return topo;
}

int main() {

    /*
            DAG

            5 ----> 0 <---- 4
            |              /
            |             /
            v            /
            2 ----> 3
            |
            v
            1

        One Possible Topological Order:

        5 4 2 3 1 0
    */

    int V = 6;

    vector<vector<int>> edges = {

        {5,0},
        {5,2},
        {4,0},
        {4,1},
        {2,3},
        {3,1}
    };

    vector<int> ans =
        topoSort(V, edges);

    cout << "Topological Order:\n";

    for (auto node : ans) {

        cout << node << " ";
    }

    cout << endl;

    return 0;
}