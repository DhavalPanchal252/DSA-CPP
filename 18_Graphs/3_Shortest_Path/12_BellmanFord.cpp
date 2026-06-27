#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Bellman-Ford Algorithm

--------------------------------------------------

Problem

Given a weighted directed graph,

find the shortest distance from

Source -------------> Every Vertex

Bellman-Ford works even if the graph
contains negative edge weights.

It can also detect a negative weight cycle.

--------------------------------------------------

Graph Representation

Edge List

{u, v, weight}

Example

0 ----5----> 1
 \           |
  \          |
   4        -2
    \        |
     v       v
      2 ---> 3

--------------------------------------------------

Why Bellman-Ford?

Dijkstra

✓ Positive Weights

✗ Negative Weights

--------------------------------

Bellman-Ford

✓ Positive Weights

✓ Negative Weights

✓ Detects Negative Cycle

--------------------------------------------------

Core Idea

A shortest path can contain

at most (V - 1) edges.

Therefore,

Relax every edge

(V - 1) times.

--------------------------------------------------

Relaxation

Suppose

u ----w----> v

If

dist[u] + w < dist[v]

Update

dist[v]

--------------------------------------------------

Negative Cycle Detection

After performing

(V - 1) relaxations,

perform one more relaxation.

If any distance can still be reduced,

then

Negative Weight Cycle Exists.

--------------------------------------------------

Time Complexity

O(V × E)

--------------------------------------------------

Space Complexity

O(V)

==================================================
*/

vector<int> bellmanFord(int V,
                        vector<vector<int>>& edges,
                        int src)
{
    // Distance Array

    vector<int> dist(V, 1e8);

    dist[src] = 0;

    // Relax all edges (V-1) times

    for (int i = 0; i < V - 1; i++)
    {
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (dist[u] != 1e8 &&
                dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Detect Negative Weight Cycle

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        if (dist[u] != 1e8 &&
            dist[u] + w < dist[v])
        {
            return {-1};
        }
    }

    return dist;
}

int main()
{
    /*
            Graph

            0
          /   \
        5/     \4
        /       \
       1 ----3-->2
       |         |
      -2         |
       |         |
       v         |
       3<--------+

        Edge List

        0 -> 1 (5)
        0 -> 2 (4)
        1 -> 2 (3)
        1 -> 3 (-2)
        2 -> 3 (2)

        Source = 0

        Shortest Distances

        0 : 0
        1 : 5
        2 : 4
        3 : 3
    */

    int V = 4;

    vector<vector<int>> edges =
    {
        {0,1,5},
        {0,2,4},
        {1,2,3},
        {1,3,-2},
        {2,3,2}
    };

    int src = 0;

    vector<int> ans = bellmanFord(V, edges, src);

    if (ans.size() == 1 && ans[0] == -1)
    {
        cout << "Negative Weight Cycle Detected\n";
    }
    else
    {
        cout << "Shortest Distances:\n";

        for (int i = 0; i < V; i++)
        {
            cout << "Node " << i
                 << " : "
                 << ans[i]
                 << endl;
        }
    }

    return 0;
}