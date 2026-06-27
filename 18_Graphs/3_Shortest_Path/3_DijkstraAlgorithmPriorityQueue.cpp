#include <bits/stdc++.h>
using namespace std;

/*
==================================================
                Dijkstra Algorithm

            (Shortest Path)

--------------------------------------------------

Applicable:

1. Weighted Graph
2. Non-Negative Edge Weights

--------------------------------------------------

Idea:

Always process the node having the
minimum distance from the source.

Use a Min Heap (Priority Queue).

--------------------------------------------------

Steps:

1. Build Adjacency List.
2. Initialize distance array with INF.
3. Set source distance = 0.
4. Push {0, source} into Min Heap.
5. While heap is not empty:
      - Pop minimum distance node.
      - Ignore outdated entries.
      - Relax all adjacent edges.
6. Return distance array.

--------------------------------------------------

Why Min Heap?

The priority queue always gives the
node having the smallest distance.

--------------------------------------------------

Time Complexity:

O((V + E) log V)

Space Complexity:

O(V + E)

==================================================
*/

vector<int> dijkstra(int V,
                     vector<vector<int>>& edges,
                     int src) {

    vector<pair<int,int>> adj[V];

    // Build Adjacency List

    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});     // Undirected Graph
    }

    // Distance Array

    vector<int> dist(V, 1e9);
    dist[src] = 0;

    // Min Heap
    // {distance, node}

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, src});

    while (!pq.empty()) {

        int d = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        // Ignore outdated entry

        if (d > dist[u])
            continue;

        // Relax all neighbours

        for (auto &it : adj[u]) {

            int v = it.first;
            int weight = it.second;

            if (d + weight < dist[v]) {

                dist[v] = d + weight;

                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {

    /*
                Graph

             4
        0 -------- 1
        |          |
      1 |          | 2
        |          |
        2 -------- 3
             5

        Edges

        0 - 1 = 4
        0 - 2 = 1
        1 - 3 = 2
        2 - 3 = 5

        Source = 0

        Shortest Distance

        0 : 0
        1 : 4
        2 : 1
        3 : 6
    */

    int V = 4;

    vector<vector<int>> edges = {

        {0,1,4},
        {0,2,1},
        {1,3,2},
        {2,3,5}
    };

    int src = 0;

    vector<int> dist = dijkstra(V, edges, src);

    cout << "Shortest Distance from Source " << src << "\n\n";

    for (int i = 0; i < V; i++) {

        cout << i << " : " << dist[i] << endl;
    }

    return 0;
}