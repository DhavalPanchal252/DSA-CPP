#include <bits/stdc++.h>
using namespace std;

/*
==================================================
      Find the City With the Smallest Number
        of Neighbors at a Threshold Distance

              Floyd-Warshall Algorithm

--------------------------------------------------

Problem

Given

n cities

and weighted undirected edges,

find the city that can reach the
smallest number of cities whose
shortest distance is

<= distanceThreshold.

If multiple cities have the same count,

return the city with the largest index.

--------------------------------------------------

Graph

Undirected Weighted Graph

Example

        3
    0 ------ 1
    |        |
   8|        |1
    |        |
    2 ------ 3
        2

Threshold = 4

--------------------------------------------------

Why Floyd-Warshall?

Need shortest distance

from

Every City

to

Every Other City.

Floyd-Warshall computes

All-Pairs Shortest Paths

in one algorithm.

--------------------------------------------------

Idea

Initially,

dist[i][j]

contains direct edge weight.

Then,

allow every vertex one by one
to become an intermediate vertex.

Suppose

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

Choosing Answer

For every city,

count how many cities satisfy

dist[i][j] <= threshold

Choose

Minimum Count

If tie,

choose Larger City Number.

--------------------------------------------------

Time Complexity

Floyd-Warshall

O(N³)

Counting

O(N²)

Overall

O(N³)

--------------------------------------------------

Space Complexity

O(N²)

==================================================
*/

int findTheCity(int n,
                vector<vector<int>>& edges,
                int distanceThreshold)
{
    const int INF = 1e8;

    // Distance Matrix

    vector<vector<int>> dist(
        n,
        vector<int>(n, INF)
    );

    // Distance from a city to itself

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Fill direct edges

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];

        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall

    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][via] != INF &&
                    dist[via][j] != INF &&
                    dist[i][j] >
                    dist[i][via] + dist[via][j])
                {
                    dist[i][j] =
                        dist[i][via] + dist[via][j];
                }
            }
        }
    }

    int city = -1 ;
    int mini = INT_MAX;

    for(int i=0 ; i<n ; i++){

        int cnt = 0;
        for(int j=0 ; j<n ; j++){

            if(dist[i][j] <= distanceThreshold) cnt++;
        }

        if(cnt <= mini){
            mini = cnt;
            city = i;
        }
    }
    
    return city;
}

int main()
{
    /*
            Graph

                3
            0 ------ 1
            |        |
           8|        |1
            |        |
            2 ------ 3
                2

        Edges

        0 - 1 = 3
        1 - 2 = 1
        2 - 3 = 2
        0 - 3 = 8

        Threshold = 4

        Shortest Distances

        City 0

        0 -> 0 = 0
        0 -> 1 = 3
        0 -> 2 = 4
        0 -> 3 = 6

        Reachable = 3

        ---------------------

        City 1

        Reachable = 4

        ---------------------

        City 2

        Reachable = 4

        ---------------------

        City 3

        Reachable = 3

        Smallest Reachable Count = 3

        Tie between

        City 0 and City 3

        Answer = 3
    */

    int n = 4;

    vector<vector<int>> edges =
    {
        {0,1,3},
        {1,2,1},
        {2,3,2},
        {0,3,8}
    };

    int distanceThreshold = 4;

    cout << "Answer City = "
         << findTheCity(n, edges, distanceThreshold)
         << endl;

    return 0;
}