#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Dijkstra Algorithm

              (Using Set)

--------------------------------------------------

Applicable:

1. Weighted Graph
2. Non-Negative Edge Weights

--------------------------------------------------

Why use Set?

Unlike Priority Queue,

Set allows us to remove the old
(distance, node) pair before inserting
the new one.

So,

Every node has only ONE valid entry
inside the set.

No duplicate entries.
No outdated distances.

--------------------------------------------------

Priority Queue

        (10,2)
        (5,2)

Old distance cannot be removed.

Need:

if(d > dist[u]) continue;

--------------------------------------------------

Set

Before inserting

(5,2)

we erase

(10,2)

Only one entry remains.

Hence no stale entries.

--------------------------------------------------

Time Complexity

Insertion : O(log V)

Deletion  : O(log V)

Overall

O((V + E) log V)

--------------------------------------------------

Space Complexity

O(V + E)

==================================================
*/

vector<int> dijkstra(int V,
                     vector<vector<int>>& edges,
                     int src) {

    vector<pair<int,int>> adj[V];

    for (auto &edge : edges) {

        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   
    }


    vector<int> dist(V, 1e9);

    dist[src] = 0;

    // Set stores

    // {distance, node}

    set<pair<int,int>> st;

    st.insert({0, src});

    while (!st.empty()) {

        // Smallest distance node

        auto it = *st.begin();

        int d = it.first;
        int u = it.second;

        st.erase(st.begin());

        // Relax neighbours

        for (auto &nbr : adj[u]) {

            int v = nbr.first;
            int weight = nbr.second;

            if (d + weight < dist[v]) {

                // Remove old pair if it exists

                if (dist[v] != 1e9) {

                    st.erase({dist[v], v});
                }

                // Update distance

                dist[v] = d + weight;

                st.insert({dist[v], v});
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