#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Number of Provinces (DFS)

    Province:
    - A group of directly or indirectly
      connected cities.

    Approach:
    1. Convert adjacency matrix into
       adjacency list.
    2. Traverse each unvisited city.
    3. Run DFS from that city.
    4. Every new DFS call represents
       a new province.

--------------------------------------------------

    Time Complexity : O(V²)

    Space Complexity: O(V + E)

==================================================
*/

void dfs(int u,
         vector<vector<int>>& adj,
         vector<int>& vis) {

    vis[u] = 1;

    for (auto& v : adj[u]) {

        if (!vis[v]) {

            dfs(v, adj, vis);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {

    int n = isConnected.size();

    // Convert Matrix -> Adjacency List
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if (isConnected[i][j] == 1 && i != j) {

                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int provinces = 0;

    vector<int> vis(n, 0);

    for (int i = 0; i < n; i++) {

        if (!vis[i]) {

            provinces++;

            dfs(i, adj, vis);
        }
    }

    return provinces;
}

int main() {

    /*
            isConnected Matrix

                0 1 2
            0 [1 1 0]
            1 [1 1 0]
            2 [0 0 1]

        Graph:

            0 ----- 1

            2

        Provinces:
        {0,1}
        {2}

        Answer = 2
    */

    int n;
    cin >> n;

    vector<vector<int>> isConnected(
        n, vector<int>(n));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            cin >> isConnected[i][j];
        }
    }

    cout << "Number of Provinces: "
         << findCircleNum(isConnected)
         << endl;

    return 0;
}