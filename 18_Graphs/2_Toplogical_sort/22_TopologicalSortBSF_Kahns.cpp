#include <bits/stdc++.h>
using namespace std;

/*
==================================================
      Topological Sort (Kahn's Algorithm)

    Applicable:
    Directed Acyclic Graph (DAG)

--------------------------------------------------

    Idea:

    1. Compute indegree of every node.
    2. Push all nodes having indegree 0
       into the queue.
    3. Pop node from queue.
    4. Add it to answer.
    5. Reduce indegree of its neighbours.
    6. If neighbour indegree becomes 0,
       push it into queue.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

vector<int> topoSort(int V,
                     vector<vector<int>>& edges) {

    vector<int> adj[V];

    // Build Adjacency List

    for (auto& edge : edges) {

        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
    }

    vector<int> indegree(V, 0);

    // Calculate Indegree

    for (int i = 0; i < V; i++) {

        for (auto& v : adj[i]) {

            indegree[v]++;
        }
    }

    queue<int> q;

    // Push all nodes having indegree 0

    for (int i = 0; i < V; i++) {

        if (indegree[i] == 0) {

            q.push(i);
        }
    }

    vector<int> topo;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (auto& v : adj[node]) {

            indegree[v]--;

            if (indegree[v] == 0) {

                q.push(v);
            }
        }
    }

    return topo;
}

int main() {

    /*
            DAG

            5 ----> 0 <---- 4
            |              /
            |             /
            v            /
            2 ----> 3
            |
            v
            1

        One Possible Topological Order:

        4 5 0 2 3 1
    */

    int V = 6;

    vector<vector<int>> edges = {

        {5,0},
        {5,2},
        {4,0},
        {4,1},
        {2,3},
        {3,1}
    };

    vector<int> ans = topoSort(V, edges);

    cout << "Topological Order:\n";

    for (auto node : ans) {

        cout << node << " ";
    }

    cout << endl;

    return 0;
}