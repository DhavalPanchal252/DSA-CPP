#include <bits/stdc++.h>
using namespace std;

/*
==================================================
    Number of Ways to Arrive at Destination

          Dijkstra + Path Counting

--------------------------------------------------

Problem

Given an undirected weighted graph,

find

1. Shortest distance from source (0)
2. Number of shortest paths to destination.

--------------------------------------------------

Graph

u ----weight---- v

Roads are bidirectional.

--------------------------------------------------

Idea

Run Dijkstra.

Maintain

dist[i]
=
Shortest distance from source to i.

ways[i]
=
Number of shortest paths to i.

--------------------------------------------------

Relaxation

Case 1

Found a shorter path

dist[v] > dist[u] + w

Update

dist[v]
ways[v] = ways[u]

--------------------------------------------------

Case 2

Found another shortest path

dist[v] == dist[u] + w

Increase

ways[v] += ways[u]

--------------------------------------------------

Priority Queue

{distance, node}

--------------------------------------------------

Time Complexity

O((V + E) log V)

Space Complexity

O(V + E)

==================================================
*/

int countPaths(int n, vector<vector<int>>& roads)
{
    // Adjacency List

    vector<vector<pair<int,int>>> adj(n);

    for (auto &road : roads)
    {
        int u = road[0];
        int v = road[1];
        int w = road[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Distance Array

    vector<int> dist(n, 1e9);

    // Number of Shortest Paths

    vector<int> ways(n, 0);

    dist[0] = 0;
    ways[0] = 1;

    // {distance, node}

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, 0});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int d = it.first;
        int u = it.second;

        // Ignore outdated entry

        if (d > dist[u])
            continue;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;

            // Better shortest path

            if (dist[v] > d + w)
            {
                dist[v] = d + w;

                ways[v] = ways[u];

                pq.push({dist[v], v});
            }

            // Another shortest path

            else if (dist[v] == d + w)
            {
                ways[v] += ways[u];
            }
        }
    }

    return ways[n - 1];
}

int main()
{
    /*
            Graph

            0
          /   \
         1     2
          \   /
            3

        Roads

        0-1 = 1
        0-2 = 1
        1-3 = 1
        2-3 = 1

        Shortest Distance

        0 -> 1 -> 3 = 2

        0 -> 2 -> 3 = 2

        Number of Shortest Paths = 2
    */

    int n = 4;

    vector<vector<int>> roads =
    {
        {0,1,1},
        {0,2,1},
        {1,3,1},
        {2,3,1}
    };

    cout << "Number of Shortest Paths = "
         << countPaths(n, roads)
         << endl;

    return 0;
}