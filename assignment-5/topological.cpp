#include <bits/stdc++.h>
using namespace std;

//  TC : O(E+VlogV) and SC : O(V+E)

/*
Sample Input 0

4 3
3 0
1 0
2 0
Sample Output 0

1 2 3 0
*/
void topologicalSort(int V, vector<vector<int>> &adj) {
    vector<int> indegree(V, 0);

    // Step 1: Compute indegree of every vertex
    for (int u = 0; u < V; u++) {
        for (auto v : adj[u]) {
            indegree[v]++;
        }   
    }

    // Step 2: Use min-heap to always pick smallest node first
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    vector<int> topo;

    // Step 3: Standard Kahn's algorithm with priority queue
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        topo.push_back(node);

        for (auto neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) pq.push(neighbor);
        }
    }

    // Step 4: Print topological order
    for (int i = 0; i < V; i++) {
        cout << topo[i];
        if (i != V - 1) cout << " ";
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    topologicalSort(V, adj);
    return 0;
}
