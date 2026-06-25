#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Connected Components (DFS)

    Connected Component:
    - A group of vertices where every
      vertex is reachable from every
      other vertex in the group.

    Steps:
    1. Maintain a visited array.
    2. Traverse all vertices.
    3. If a vertex is unvisited:
       - Start DFS from it.
       - Collect all reachable nodes.
       - Store them as one component.
    4. Repeat until all vertices
       are visited.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

void dfs(int u,
         vector<vector<int>>& adj,
         vector<int>& vis,
         vector<int>& component) {

    vis[u] = 1;

    component.push_back(u);

    for (auto& v : adj[u]) {

        if (!vis[v]) {

            dfs(v, adj, vis, component);
        }
    }
}

vector<vector<int>> getComponents(int V,
                                  vector<vector<int>>& adj) {

    vector<int> vis(V, 0);

    vector<vector<int>> ans;

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            vector<int> component;

            dfs(i, adj, vis, component);

            ans.push_back(component);
        }
    }

    return ans;
}

int main() {

    /*
            Graph

            0 --- 1
            |
            2

            3 --- 4

            5

        Connected Components:

        {0,1,2}
        {3,4}
        {5}
    */

    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {

        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected Graph
    }

    vector<vector<int>> components =
        getComponents(V, adj);

    cout << "Connected Components:\n";

    for (int i = 0; i < components.size(); i++) {

        cout << "Component " << i + 1 << ": ";

        for (auto node : components[i]) {

            cout << node << " ";
        }

        cout << "\n";
    }

    return 0;
}