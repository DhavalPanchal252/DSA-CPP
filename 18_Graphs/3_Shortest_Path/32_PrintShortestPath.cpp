#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Print Shortest Path (Dijkstra)

--------------------------------------------------

Problem:

Given a weighted graph,
print the shortest path from

        Source (1)
            to
     Destination (N)

--------------------------------------------------

Approach:

1. Run Dijkstra's Algorithm.
2. Maintain a parent array.
3. Whenever a shorter path is found,
   update the parent.
4. After Dijkstra finishes,
   backtrack from destination using
   the parent array.

--------------------------------------------------

Parent Array

Example

Shortest Path

1 ----> 2 ----> 4 ----> 5

Parent Array

parent[1] = 1
parent[2] = 1
parent[4] = 2
parent[5] = 4

Now start from destination

5 → 4 → 2 → 1

Reverse

1 → 2 → 4 → 5

--------------------------------------------------

Time Complexity

O((V + E) log V)

Space Complexity

O(V + E)

==================================================
*/

vector<int> shortestPath(int V,
                         vector<vector<int>>& edges) {

    vector<pair<int,int>> adj[V + 1];

    // Build Graph

    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // Undirected Graph
    }

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    vector<int> dist(V + 1, 1e9);
    vector<int> parent(V + 1);

    for (int i = 1; i <= V; i++)
        parent[i] = i;

    dist[1] = 0;

    pq.push({0, 1});

    while (!pq.empty()) {

        int d = pq.top().first;
        int u = pq.top().second;

        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &it : adj[u]) {

            int v = it.first;
            int w = it.second;

            if (d + w < dist[v]) {

                dist[v] = d + w;

                parent[v] = u;

                pq.push({dist[v], v});
            }
        }
    }

    // Destination = V

    if (dist[V] == 1e9)
        return {-1};

    vector<int> path;

    int node = V;

    while (parent[node] != node) {

        path.push_back(node);

        node = parent[node];
    }

    path.push_back(1);

    reverse(path.begin(), path.end());

    return path;
}

int main() {

    /*
                Graph

          1 -------- 2
          | \        |
        4 |  1       | 2
          |    \     |
          3 ---- 4 --5
             3     1

        Edges

        1 - 2 = 2
        1 - 4 = 1
        1 - 3 = 4
        2 - 5 = 2
        4 - 5 = 1
        3 - 4 = 3

        Source = 1
        Destination = 5

        Shortest Path

        1 -> 4 -> 5
    */

    int V = 5;

    vector<vector<int>> edges = {

        {1,2,2},
        {1,4,1},
        {1,3,4},
        {2,5,2},
        {4,5,1},
        {3,4,3}
    };

    vector<int> path = shortestPath(V, edges);

    if (path[0] == -1) {

        cout << "No Path Exists\n";
    }

    else {

        cout << "Shortest Path\n\n";

        for (auto &node : path)
            cout << node << " ";
    }

    return 0;
}