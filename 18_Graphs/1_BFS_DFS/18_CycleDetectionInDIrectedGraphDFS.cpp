#include <bits/stdc++.h>
using namespace std;

/*
==================================================
    Cycle Detection in Directed Graph (DFS)

    Idea:

    vis[node]
    -> Node has been visited before

    pathVis[node]
    -> Node is currently present in
       the DFS recursion path

--------------------------------------------------

    Cycle Condition:

    During DFS,

    if we reach a node that is already
    present in the current DFS path:

        pathVis[v] == 1

    then a cycle exists.

--------------------------------------------------

    Steps:

    1. Mark node visited.
    2. Mark node in current path.
    3. Traverse all neighbours.
    4. If neighbour is unvisited:
         DFS on neighbour.
    5. If neighbour is already in
       current DFS path:
         Cycle Found.
    6. Before returning,
       remove current node from path.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)
                       + Recursion Stack

==================================================
*/

bool dfs(int u,
         vector<int>& vis,
         vector<int>& pathVis,
         vector<vector<int>>& adj) {

    vis[u] = 1;
    pathVis[u] = 1;

    for (auto& v : adj[u]) {

        if (!vis[v]) {

            if (dfs(v,
                    vis,
                    pathVis,
                    adj))
                return true;
        }

        else if (pathVis[v]) {

            return true;
        }
    }

    pathVis[u] = 0;

    return false;
}

bool isCyclic(int V,
              vector<vector<int>>& edges) {

    vector<vector<int>> adj(V);

    // Build adjacency list

    for (auto& e : edges) {

        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
    }

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    // Handle disconnected graph

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            if (dfs(i,
                    vis,
                    pathVis,
                    adj))
                return true;
        }
    }

    return false;
}

int main() {

    /*
        Graph

        0 → 1 → 2
            ↑   ↓
            └───┘

        Cycle:
        1 → 2 → 1

        Answer = Yes
    */

    int V = 3;

    vector<vector<int>> edges = {

        {0,1},
        {1,2},
        {2,1}
    };

    if (isCyclic(V, edges))
        cout << "Cycle Found\n";
    else
        cout << "No Cycle Found\n";

    return 0;
}