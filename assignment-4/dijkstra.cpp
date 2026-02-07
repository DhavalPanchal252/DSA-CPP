#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // adjacency list: node -> [(neighbor, weight)]
    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove if graph is directed
    }

    int s; 
    cin >> s;

    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    // min-heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue; // outdated distance

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    // print answer
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }

    return 0;
}
