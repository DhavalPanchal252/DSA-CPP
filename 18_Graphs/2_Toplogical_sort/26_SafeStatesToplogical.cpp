#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Eventual Safe States (BFS)

        Reverse Graph + Kahn's Algorithm

--------------------------------------------------

    Definition:

    A node is SAFE if every path
    starting from it eventually
    reaches a terminal node.

--------------------------------------------------

    Terminal Node:

    A node having no outgoing edges.

--------------------------------------------------

    Key Observation:

    Instead of finding unsafe nodes,
    start from all terminal nodes.

    Reverse the graph.

    Perform Kahn's Algorithm on the
    reversed graph.

--------------------------------------------------

    Steps:

    1. Reverse all edges.
    2. Compute Outdegree of every node.
    3. Push all terminal nodes
       (outdegree = 0).
    4. BFS.
    5. Whenever a node's outdegree
       becomes 0, it is also safe.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V + E)

==================================================
*/

vector<int> eventualSafeNodes(
    vector<vector<int>>& graph) {

    int V = graph.size();

    vector<vector<int>> revAdj(V);

    // Stores number of outgoing edges
    vector<int> outDegree(V, 0);

    // Build Reverse Graph

    for (int u = 0; u < V; u++) {

        outDegree[u] = graph[u].size();

        for (auto& v : graph[u]) {

            revAdj[v].push_back(u);
        }
    }

    queue<int> q;

    // Push all terminal nodes

    for (int i = 0; i < V; i++) {

        if (outDegree[i] == 0) {

            q.push(i);
        }
    }

    vector<int> safeNodes;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        safeNodes.push_back(node);

        for (auto& parent : revAdj[node]) {

            outDegree[parent]--;

            if (outDegree[parent] == 0) {

                q.push(parent);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}

int main() {

    /*
            Original Graph

            0 → 1
            ↓
            2

            1 → 2
            2 → 3
            3

            4 → 5
            ↑   ↓
            └───┘

        Safe Nodes:

        0 1 2 3

        Unsafe Nodes:

        4 5
    */

    vector<vector<int>> graph = {

        {1,2},   // 0
        {2},     // 1
        {3},     // 2
        {},      // 3 (Terminal)
        {5},     // 4
        {4}      // 5
    };

    vector<int> ans = eventualSafeNodes(graph);

    cout << "Safe Nodes:\n";

    for (auto node : ans) {

        cout << node << " ";
    }

    cout << endl;

    return 0;
}