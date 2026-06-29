#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Network Delay Time

             Dijkstra Algorithm

--------------------------------------------------

Problem

There are

n nodes (1 to n)

and directed edges

u ----time----> v

Starting from node k,

find the minimum time required for the
signal to reach every node.

If any node cannot receive the signal,
return -1.

Otherwise,

return the maximum time among all nodes.

--------------------------------------------------

Graph

Directed Weighted Graph

Example

        2
      /   \
     1     3
      \   /
        4

Signal starts from node 2.

--------------------------------------------------

Why Dijkstra?

We need the shortest time from

Source (k)

to every other node.

Since

All edge weights are positive,

Dijkstra is the optimal algorithm.

--------------------------------------------------

State stored in Priority Queue

{distance, node}

Example

{5, 3}

means

Current shortest distance to node 3 is 5.

--------------------------------------------------

Relaxation

Suppose

u ----w----> v

If

dist[u] + w < dist[v]

Update

dist[v]

Push the updated state into Priority Queue.

--------------------------------------------------

Outdated Entry

Sometimes

a node is inserted multiple times
into the priority queue.

Ignore an entry if

currentDistance > dist[node]

--------------------------------------------------

Answer

After Dijkstra,

If any node is unreachable

return -1.

Otherwise,

answer is

maximum(dist[i])

because the signal reaches all nodes
only after the farthest node receives it.

--------------------------------------------------

Time Complexity

O((V + E) log V)

--------------------------------------------------

Space Complexity

O(V + E)

==================================================
*/

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    // Adjacency List
    // {neighbor, weight}

    vector<vector<pair<int,int>>> adj(n + 1);

    for (auto &edge : times)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        adj[u].push_back({v, w});
    }

    // Distance Array

    vector<int> dist(n + 1, 1e9);

    dist[k] = 0;

    // {distance, node}

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, k});

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

            if (dist[v] > d + w)
            {
                dist[v] = d + w;

                pq.push({dist[v], v});
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == 1e9)
            return -1;

        answer = max(answer, dist[i]);
    }

    return answer;
}

int main()
{
    /*
            Graph

            2
          / | \
         1  1  1
        /   |   \
       1    3    4

        Edges

        2 -> 1 (1)
        2 -> 3 (1)
        3 -> 4 (1)

        Source = 2

        Shortest Times

        Node 2 = 0
        Node 1 = 1
        Node 3 = 1
        Node 4 = 2

        Maximum Time = 2

        Answer = 2
    */

    int n = 4;
    int k = 2;

    vector<vector<int>> times =
    {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };

    cout << "Network Delay Time = "
         << networkDelayTime(times, n, k)
         << endl;

    return 0;
}