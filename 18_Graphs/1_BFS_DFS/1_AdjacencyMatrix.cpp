#include <bits/stdc++.h>
using namespace std;

int main() {

    // Vertices : n , Edges : m
    int n, m;
    cin >> n >> m;

    // Adjacency Matrix initialized with 0
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    // Next m lines contain edges u-v : O(v^2)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;   // For undirected graph
    }

    // Print adjacency Matrix
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}