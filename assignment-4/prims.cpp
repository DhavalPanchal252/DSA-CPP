#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Adjacency list: node -> [(adjacent_node, weight)]
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // since graph is undirected
    }

    vector<int> vis(n + 1, 0); // visited array
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // start from node 1
    pq.push({0, 1}); // {weight, node}
    int totalWeight = 0;

    while (!pq.empty()) {
        auto [w, node] = pq.top();
        pq.pop();

        if (vis[node]) continue; // already in MST
        vis[node] = 1;
        totalWeight += w;

        // push all adjacent edges
        for (auto it : adj[node]) {
            int adjNode = it.first;
            int weight = it.second;
            if (!vis[adjNode]) pq.push({weight, adjNode});
        }
    }

    cout << totalWeight;
    return 0;
}
