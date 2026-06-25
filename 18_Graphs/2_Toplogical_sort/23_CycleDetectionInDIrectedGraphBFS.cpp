#include <bits/stdc++.h>
using namespace std;

/*
==================================================
    Cycle Detection in Directed Graph (BFS)

            Kahn's Algorithm

--------------------------------------------------

    Idea:

    Topological Sort is possible only
    for a Directed Acyclic Graph (DAG).

    If the graph contains a cycle,
    some nodes will never get
    indegree = 0.

--------------------------------------------------

    Steps:

    1. Build adjacency list.
    2. Compute indegree of each node.
    3. Push all nodes with indegree 0.
    4. Perform BFS.
    5. Count processed nodes.

--------------------------------------------------

    Cycle Condition:

    If processed nodes < V

        => Cycle Exists

    Else

        => No Cycle

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

bool isCyclic(int V,
              vector<vector<int>>& edges) {

    vector<int> adj[V];

    // Build adjacency list

    for (auto& edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    vector<int> indegree(V, 0);

    // Calculate indegree

    for (int i = 0; i < V; i++) {

        for (auto& v : adj[i]) {

            indegree[v]++;
        }
    }

    queue<int> q;

    // Push nodes having indegree 0

    for (int i = 0; i < V; i++) {

        if (indegree[i] == 0) {

            q.push(i);
        }
    }

    int countNodes = 0;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        countNodes++;

        for (auto& v : adj[node]) {

            indegree[v]--;

            if (indegree[v] == 0) {

                q.push(v);
            }
        }
    }

    // If all nodes are not processed,
    // cycle exists.

    return countNodes != V;
}

int main() {

    /*
            Graph

            0 → 1 → 2
            ↑       ↓
            └───────┘

            Cycle:
            0 → 1 → 2 → 0
    */

    int V = 3;

    vector<vector<int>> edges = {

        {0,1},
        {1,2},
        {2,0}
    };

    if (isCyclic(V, edges))
        cout << "Cycle Exists\n";
    else
        cout << "No Cycle Exists\n";

    return 0;
}