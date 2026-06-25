#include <bits/stdc++.h>
using namespace std;

/*
==================================================
    Cycle Detection in Undirected Graph (BFS)

    Idea:

    - Traverse every connected component.
    - Store (node, parent) in queue.
    - If we find an already visited
      neighbour which is NOT the parent,
      then a cycle exists.

--------------------------------------------------

    Why Parent?

    Example:

        0 ----- 1

    While visiting 1, we again see 0.

    This is NOT a cycle because
    0 is the parent of 1.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

bool bfs(int src,
         vector<int>& vis,
         vector<int> adj[]) {

    queue<pair<int,int>> q;

    vis[src] = 1;

    q.push({src, -1});

    while (!q.empty()) {

        int u = q.front().first;
        int parent = q.front().second;

        q.pop();

        for (auto& v : adj[u]) {

            if (!vis[v]) {

                vis[v] = 1;

                q.push({v, u});
            }

            else if (v != parent) {

                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {

    vector<int> vis(V, 0);

    // Traverse all connected components

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            if (bfs(i, vis, adj))
                return true;
        }
    }

    return false;
}

int main() {

    /*
        Graph

        Component 1

            0 ----- 1
            |       |
            |       |
            3 ----- 2

        Component 2

            4 ----- 5


        Adjacency List

        0 -> 1 3
        1 -> 0 2
        2 -> 1 3
        3 -> 0 2
        4 -> 5
        5 -> 4

        Component 1 contains a cycle.

        Answer = Yes
    */

    int V = 6;

    vector<int> adj[V];

    // Component 1 (Cycle)

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    // Component 2 (No Cycle)

    adj[4].push_back(5);
    adj[5].push_back(4);

    if (isCycle(V, adj))
        cout << "Cycle Found\n";
    else
        cout << "No Cycle Found\n";

    return 0;
}