#include <bits/stdc++.h>
using namespace std;

/*
==================================================
          Floyd-Warshall Algorithm

        All-Pairs Shortest Path (APSP)

--------------------------------------------------

Problem

Given a weighted directed graph in the form
of an adjacency matrix,

find the shortest distance between

every pair of vertices.

--------------------------------------------------

Graph Representation

dist[i][j]

=

Weight of edge

i --------> j

If there is no direct edge,

dist[i][j] = INF (10^8)

--------------------------------------------------

Why Floyd-Warshall?

Dijkstra

✓ Single Source Shortest Path

Bellman-Ford

✓ Single Source Shortest Path
✓ Negative Edges

Floyd-Warshall

✓ Shortest Path Between Every Pair
✓ Handles Negative Edge Weights
✗ No Negative Weight Cycle

--------------------------------------------------

Core Idea

Suppose we want the shortest path

i -------------> j

Instead of travelling directly,

what if we pass through another node?

i -----> via -----> j

If

dist[i][via] + dist[via][j]

is smaller,

update

dist[i][j].

--------------------------------------------------

DP Relation

dist[i][j] =

min(

dist[i][j],

dist[i][via] + dist[via][j]

)

--------------------------------------------------

Loop Order

The outermost loop must be

via

because

we gradually allow

0...

via

to become intermediate vertices.

for(via)

    for(i)

        for(j)

--------------------------------------------------

Skip Impossible Paths

If

dist[i][via] == INF

or

dist[via][j] == INF

then

there is no valid path through

via.

--------------------------------------------------

Time Complexity

O(N³)

--------------------------------------------------

Space Complexity

O(1)

(Matrix updated in-place)

==================================================
*/

void floydWarshall(vector<vector<int>> &dist)
{
    int n = dist.size();

    const int INF = 100000000;

    // Allow every vertex to become
    // an intermediate vertex.

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][via] != INF &&
                    dist[via][j] != INF &&
                    dist[i][j] > dist[i][via] + dist[via][j])
                {
                    dist[i][j] =
                        dist[i][via] + dist[via][j];
                }
            }
        }
    }
}

int main()
{
    /*
            Graph

              4
        0 ---------> 1
        |            |
      5 |            | 6
        |            |
        v            v
        3 <--------- 2
            1

        Matrix

             0   4 INF   5
           INF   0   6 INF
           INF INF   0   1
           INF INF INF   0

        Expected Shortest Distances

             0   4  10   5
           INF   0   6   7
           INF INF   0   1
           INF INF INF   0
    */

    const int INF = 100000000;

    vector<vector<int>> dist =
    {
        {0,   4, INF, 5},
        {INF, 0,   6, INF},
        {INF, INF, 0, 1},
        {INF, INF, INF, 0}
    };

    floydWarshall(dist);

    cout << "Shortest Distance Matrix\n\n";

    for (auto &row : dist)
    {
        for (int x : row)
        {
            if (x == INF)
                cout << "INF ";
            else
                cout << setw(3) << x << " ";
        }
        cout << endl;
    }

    return 0;
}