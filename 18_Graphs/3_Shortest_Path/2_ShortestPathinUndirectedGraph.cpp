#include <bits/stdc++.h>
using namespace std;

/*
==================================================
    Shortest Path in Undirected Graph
            (Unit Weight)

                BFS

--------------------------------------------------

    Applicable:

    Undirected Graph
    Unweighted Graph
    (Every edge has weight = 1)

--------------------------------------------------

    Idea:

    Since every edge has equal weight,
    BFS always reaches a node using the
    shortest possible path.

    Therefore,

    First time a node is visited
    => Shortest distance found.

--------------------------------------------------

    Steps:

    1. Build Adjacency List.
    2. Initialize distance array with -1.
    3. Push source node into queue.
    4. Perform BFS.
    5. Update neighbour distance as

            dist[v] = dist[u] + 1

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

vector<int> shortestPath(int V,
                         vector<vector<int>>& edges,
                         int src) {

    vector<int> adj[V];

    // Build Adjacency List

    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> vis(V, 0);
    vector<int> dist(V, -1);

    queue<int> q;

    q.push(src);

    vis[src] = 1;
    dist[src] = 0;

    while (!q.empty()) {

        int u = q.front();
        q.pop();

        for (auto &v : adj[u]) {

            if (!vis[v]) {

                vis[v] = 1;
                dist[v] = dist[u] + 1;

                q.push(v);
            }
        }
    }

    return dist;
}

int main() {

    /*
            Graph

                  0
                /   \
               1     2
              / \     \
             3   4     5

        Edges

        0 - 1
        0 - 2
        1 - 3
        1 - 4
        2 - 5

        Source = 0

        Shortest Distance

        0 : 0
        1 : 1
        2 : 1
        3 : 2
        4 : 2
        5 : 2
    */

    int V = 6;

    vector<vector<int>> edges = {

        {0,1},
        {0,2},
        {1,3},
        {1,4},
        {2,5}
    };

    int src = 0;

    vector<int> dist = shortestPath(V, edges, src);

    cout << "Shortest Distance from Node " << src << "\n\n";

    for (int i = 0; i < V; i++) {

        cout << i << " : " << dist[i] << endl;
    }

    return 0;
}