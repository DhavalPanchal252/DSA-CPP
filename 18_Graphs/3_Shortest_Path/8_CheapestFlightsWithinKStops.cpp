#include <bits/stdc++.h>
using namespace std;

/*
==================================================
      Cheapest Flights Within K Stops

                BFS + Queue

--------------------------------------------------

Problem

Given

n cities
flights = {u, v, price}

Find the cheapest price from

src -------------> dst

using at most K stops.

--------------------------------------------------

Graph

Each flight

u ----price----> v

--------------------------------------------------

Why Queue instead of Priority Queue?

Normal Dijkstra

Always expands the minimum cost path.

But here,

we have an additional constraint

Maximum K Stops.

So we process the graph level by level
(number of stops) using a Queue.

--------------------------------------------------

State stored in Queue

{stops, {node, cost}}

Example

{2, {4, 350}}

means

Reached node 4

Cost = 350

Stops used = 2

--------------------------------------------------

Relaxation

For every neighbour

newCost = currentCost + edgeWeight

If

newCost < dist[neighbour]

Update distance

Push into Queue

--------------------------------------------------

Stopping Condition

If

stops > K

Ignore that state.

--------------------------------------------------

Time Complexity

O(E)

Each edge is processed at most once
per BFS level.

--------------------------------------------------

Space Complexity

O(V + E)

==================================================
*/

int findCheapestPrice(int n,
                      vector<vector<int>>& flights,
                      int src,
                      int dst,
                      int k)
{
    // Adjacency List

    vector<vector<pair<int,int>>> adj(n);

    for (auto &flight : flights)
    {
        int u = flight[0];
        int v = flight[1];
        int price = flight[2];

        adj[u].push_back({v, price});
    }

    // {stops, {node, cost}}

    queue<pair<int,pair<int,int>>> q;

    vector<int> dist(n, 1e9);

    dist[src] = 0;

    q.push({0, {src, 0}});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node  = it.second.first;
        int cost  = it.second.second;

        // Exceeded allowed stops

        if (stops > k)
            continue;

        for (auto &edge : adj[node])
        {
            int adjNode = edge.first;
            int wt      = edge.second;

            // if (cost + wt < dist[adjNode] && steps <= k)
            if (cost + wt < dist[adjNode])
            {
                dist[adjNode] = cost + wt;

                q.push(
                    {stops + 1,
                    {adjNode, dist[adjNode]}}
                );
            }
        }
    }

    if (dist[dst] == 1e9)
        return -1;

    return dist[dst];
}

int main()
{
    /*
            Flights

            0 ------100------> 1
            |                 |
           500               100
            |                 |
            v                 v
            2 <-----100-------+

        Source = 0
        Destination = 2
        K = 1

        Possible Paths

        1)

        0 -> 2

        Cost = 500

        ------------------------

        2)

        0 -> 1 -> 2

        Cost = 100 + 100

             = 200

        Stops = 1

        Answer = 200
    */

    int n = 3;

    vector<vector<int>> flights =
    {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };

    int src = 0;
    int dst = 2;
    int k = 1;

    cout << "Cheapest Price = "
         << findCheapestPrice(n, flights, src, dst, k)
         << endl;

    return 0;
}