#include <bits/stdc++.h>
using namespace std;

/*
==================================================
      Shortest Path in Binary Matrix

                    BFS

--------------------------------------------------

Problem:

Given an n x n binary matrix,

0 -> Empty Cell
1 -> Blocked Cell

Find the shortest path from

(0,0) -------> (n-1,n-1)

Movement is allowed in all
8 directions.

Return the length of the shortest path.

If no path exists, return -1.

--------------------------------------------------

Why BFS?

Every move has equal cost (=1).

Whenever all edges have equal weight,
BFS guarantees the shortest path.

--------------------------------------------------

8 Directions

↖   ↑   ↗

←   ●   →

↙   ↓   ↘

--------------------------------------------------

Algorithm

1. If source or destination is blocked,
   return -1.

2. Push source into queue.

3. Store

   {steps, {row, col}}

4. Visit all 8 neighbours.

5. If a shorter distance is found,
   update distance and push into queue.

6. Return distance of destination.

--------------------------------------------------

Time Complexity

O(N²)

Space Complexity

O(N²)

==================================================
*/

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

    int n = grid.size();

    // Source or Destination blocked

    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
        return -1;

    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    queue<pair<int, pair<int,int>>> q;

    // Source

    dist[0][0] = 1;

    q.push({1, {0, 0}});

    while (!q.empty()) {

        auto it = q.front();
        q.pop();

        int steps = it.first;
        int row = it.second.first;
        int col = it.second.second;

        // Explore all 8 directions

        for (int dr = -1; dr <= 1; dr++) {

            for (int dc = -1; dc <= 1; dc++) {

                if (dr == 0 && dc == 0)
                    continue;

                int newRow = row + dr;
                int newCol = col + dc;

                if (newRow >= 0 &&
                    newRow < n &&
                    newCol >= 0 &&
                    newCol < n &&
                    grid[newRow][newCol] == 0) {

                    if (dist[newRow][newCol] > steps + 1) {

                        dist[newRow][newCol] = steps + 1;

                        q.push({steps + 1, {newRow, newCol}});
                    }
                }
            }
        }
    }

    if (dist[n - 1][n - 1] == 1e9)
        return -1;

    return dist[n - 1][n - 1];
}

int main() {

    /*
            Grid

            0 1 0
            0 0 0
            1 0 0

        0 = Empty Cell
        1 = Blocked Cell

        Shortest Path

        (0,0)
           │
           ▼
        (1,1)
           │
           ▼
        (2,2)

        Answer = 3
    */

    vector<vector<int>> grid = {

        {0,1,0},
        {0,0,0},
        {1,0,0}
    };

    int ans = shortestPathBinaryMatrix(grid);

    cout << "Shortest Path Length = "
         << ans << endl;

    return 0;
}