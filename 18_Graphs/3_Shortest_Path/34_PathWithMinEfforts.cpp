#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Path With Minimum Effort

                Dijkstra

--------------------------------------------------

Problem

Given a grid of heights,

Find a path from

(0,0) -------------> (n-1,m-1)

such that the maximum absolute difference between adjacent cells is minimum.

--------------------------------------------------

Difference between two cells

abs(height1 - height2)

--------------------------------------------------

Why Dijkstra?

Normal Dijkstra

Distance = Sum of Weights

------------------------------

This Problem

Effort = Maximum Edge Weight

Instead of

dist + weight

we use

max(currentEffort, edgeWeight)

--------------------------------------------------

State stored in Priority Queue

{effort, {row, col}}

--------------------------------------------------

Relaxation

edgeWeight =
abs(height[current]-height[next])

newEffort =
max(currentEffort, edgeWeight)

If

newEffort < dist[next]

Update

--------------------------------------------------

Time Complexity

O((N*M) log(N*M))

Space Complexity

O(N*M)

==================================================
*/

int minimumEffortPath(vector<vector<int>>& heights) {

    int n = heights.size();
    int m = heights[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 1e9));

    dist[0][0] = 0;

    int deltaRow[] = {-1, 0, 1, 0};
    int deltaCol[] = {0, 1, 0, -1};

    priority_queue<
        pair<int, pair<int,int>>,
        vector<pair<int, pair<int,int>>>,
        greater<pair<int, pair<int,int>>>
    > pq;

    pq.push({0, {0, 0}});

    while (!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        int effort = it.first;
        int row = it.second.first;
        int col = it.second.second;

        // Destination reached

        if (row == n - 1 && col == m - 1)
            return effort;

        // Ignore outdated entry

        if (effort > dist[row][col])
            continue;

        for (int i = 0; i < 4; i++) {

            int newRow = row + deltaRow[i];
            int newCol = col + deltaCol[i];

            if (newRow >= 0 &&
                newRow < n &&
                newCol >= 0 &&
                newCol < m) {

                int edgeWeight =
                    abs(heights[row][col] -
                        heights[newRow][newCol]);

                int newEffort =
                    max(effort, edgeWeight);

                if (newEffort < dist[newRow][newCol]) {

                    dist[newRow][newCol] =
                        newEffort;

                    pq.push(
                        {newEffort,
                        {newRow, newCol}}
                    );
                }
            }
        }
    }

    return -1;
}

int main() {

    /*
            Heights

            1 2 2
            3 8 2
            5 3 5

        Path

        1 -> 2 -> 2
             ↓
             2
             ↓
             5

        Maximum Difference

        max(1,0,0,3)

        = 2

        Answer = 2
    */

    vector<vector<int>> heights = {

        {1,2,2},
        {3,8,2},
        {5,3,5}
    };

    cout << "Minimum Effort = "
         << minimumEffortPath(heights)
         << endl;

    return 0;
}