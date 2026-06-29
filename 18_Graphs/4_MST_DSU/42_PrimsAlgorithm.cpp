#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Minimum Spanning Tree (MST)

            Prim's Algorithm

--------------------------------------------------

Problem

Given an undirected weighted graph,

find the Minimum Spanning Tree (MST).

The MST is a subset of edges that

✓ Connects all vertices.
✓ Contains exactly (V - 1) edges.
✓ Has the minimum possible total weight.

--------------------------------------------------

Graph

        2
    0 ------- 1
    | \       |
   6|  \3     |8
    |   \     |
    2----4----3
       7

--------------------------------------------------

Why Prim's Algorithm?

At every step,

choose the minimum weight edge

that connects

Visited Vertex

to

Unvisited Vertex.

Repeat until all vertices
are included in the MST.

--------------------------------------------------

State stored in Priority Queue

{edgeWeight, {node, parent}}

Example

{5, {3, 1}}

means

Reach node 3

using edge weight = 5

from parent = 1

--------------------------------------------------

Algorithm

1. Start from any vertex (0).

2. Push

{0, {0, -1}}

into Priority Queue.

3. Pop the minimum edge.

4. If already visited,

skip it.

5. Otherwise,

Include it in MST.

Add its weight to answer.

6. Push all adjacent edges.

--------------------------------------------------

Why "visited" check?

A node can be pushed into the
priority queue multiple times.

Only the first (minimum weight)
entry should be processed.

--------------------------------------------------

Time Complexity

O(E log E)

(Also written as O(E log V))

--------------------------------------------------

Space Complexity

O(V + E)

==================================================
*/

int spanningTree(int V, vector<vector<int>>& edges)
{
    // Adjacency List
    // {neighbor, weight}

    vector<vector<pair<int,int>>> adj(V);

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // Stores MST edges (optional)

    vector<pair<int,int>> mst;

    vector<int> vis(V, 0);

    int mstWeight = 0;

    // {weight, {node, parent}}

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    pq.push({0, {0, -1}});

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int weight = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        // Ignore already visited nodes

        if (vis[node])
            continue;

        vis[node] = 1;

        mstWeight += weight;

        if (parent != -1)
            mst.push_back({parent, node});

        for (auto &edge : adj[node])
        {
            int adjNode = edge.first;
            int edgeWeight = edge.second;

            if (!vis[adjNode])
            {
                pq.push(
                    {edgeWeight,
                    {adjNode, node}}
                );
            }
        }
    }

    cout << "Edges in MST\n";

    for (auto &edge : mst)
    {
        cout << edge.first
             << " - "
             << edge.second
             << endl;
    }

    return mstWeight;
}

int main()
{
    /*
            Graph

                2
            0 ------- 1
            | \       |
           6|  \3     |8
            |   \     |
            2----4----3
               7

        Edge List

        0 - 1 = 2
        0 - 2 = 6
        0 - 3 = 3
        1 - 3 = 8
        2 - 3 = 7

        MST

        0 - 1 (2)
        0 - 3 (3)
        0 - 2 (6)

        Total Weight

        2 + 3 + 6 = 11
    */

    int V = 4;

    vector<vector<int>> edges =
    {
        {0,1,2},
        {0,2,6},
        {0,3,3},
        {1,3,8},
        {2,3,7}
    };

    int ans = spanningTree(V, edges);

    cout << "\nMinimum Spanning Tree Weight = "
         << ans
         << endl;

    return 0;
}