#include <bits/stdc++.h>
using namespace std;
//  TC : O(E+VlogV) and SC : O(V+E)
// Find all eventual safe nodes using Topological Sort (Kahn's Algorithm)
vector<int> findSafeNodes(int V, vector<vector<int>> &adj) {
    // Step 1: Reverse the graph and count indegree
    vector<vector<int>> revGraph(V);
    vector<int> indegree(V, 0);

    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            revGraph[v].push_back(u);  // reverse edge
            indegree[u]++;             // count indegree for reversed graph
        }
    }

    // Step 2: Use min-heap to process smallest node first
    priority_queue< int , vector<int> , greater<int> > pq;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    // Step 3: Topological sort on reversed graph
    vector<int> safe;
    while (!pq.empty()) {
        int node = pq.top();
        pq.pop();
        safe.push_back(node);

        for (int neighbor : revGraph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) pq.push(neighbor);
        }
    }

    sort(safe.begin(), safe.end());
    return safe;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> safeNodes = findSafeNodes(n, adj);
    
    if (safeNodes.empty()) {
        cout << 0;
    }
    else{
        for (int i = 0; i < int(safeNodes.size()); i++) {
            cout << safeNodes[i];
            if (i != int(safeNodes.size()) - 1) cout << " ";
        }
    }
        

    return 0;
}
