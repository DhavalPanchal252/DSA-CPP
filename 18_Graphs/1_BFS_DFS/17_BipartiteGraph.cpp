#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Bipartite Graph (DFS)

    Bipartite Graph:

    A graph is bipartite if we can
    color all vertices using only
    2 colors such that no two
    adjacent vertices have the
    same color.

--------------------------------------------------

    Colors:

    -1 -> Not Colored
     0 -> Red
     1 -> Blue

--------------------------------------------------

    DFS Approach:

    1. Color source node.
    2. Visit all neighbours.
    3. If neighbour is uncolored:
          assign opposite color.
    4. If neighbour already has
       same color:
          Not Bipartite.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

bool dfs(int u,
         int colorToAssign,
         vector<vector<int>>& graph,
         vector<int>& color) {

    color[u] = colorToAssign;

    for (auto& v : graph[u]) {

        // Not Colored Yet

        if (color[v] == -1) {

            if (!dfs(v,
                     !colorToAssign,
                     graph,
                     color))
                return false;
        }

        // Same Color Found

        else if (color[v] == colorToAssign) {

            return false;
        }
    }

    return true;
}

bool isBipartite(vector<vector<int>>& graph) {

    int V = graph.size();

    vector<int> color(V, -1);

    // Handle disconnected components

    for (int i = 0; i < V; i++) {

        if (color[i] == -1) {

            if (!dfs(i, 0,
                     graph,
                     color))
                return false;
        }
    }

    return true;
}

int main() {

    /*
        Graph

            0 ----- 1
            |       |
            |       |
            3 ----- 2

        Coloring

            0 -> Red
            1 -> Blue
            2 -> Red
            3 -> Blue

        Bipartite = YES
    */

    vector<vector<int>> graph = {

        {1,3},   // 0
        {0,2},   // 1
        {1,3},   // 2
        {0,2}    // 3
    };

    if (isBipartite(graph))
        cout << "Bipartite Graph\n";
    else
        cout << "Not Bipartite Graph\n";

    return 0;
}