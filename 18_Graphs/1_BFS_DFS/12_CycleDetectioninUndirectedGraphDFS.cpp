#include <bits/stdc++.h>
using namespace std;

/*
==================================================
    Cycle Detection in Undirected Graph (DFS)

    Idea:

    - Visit a node.
    - Mark it visited.
    - Explore all neighbours.

    If neighbour is:

    1. Unvisited
       -> DFS on it

    2. Already visited
       and NOT parent
       -> Cycle Found

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

bool dfs(int src,
         int parent,
         vector<int>& vis,
         vector<int> adj[]) {

    vis[src] = 1;

    for(auto &v : adj[src]) {

        if(!vis[v]) {

            if(dfs(v, src, vis, adj))
                return true;
        }
        // if adj node is visted and not come from parent then its cycle
        else if(v != parent) {

            return true;
        }
    }

    return false;
}

bool isCycle(int V,
             vector<int> adj[]) {

    vector<int> vis(V,0);

    // Traverse all components

    for(int i=0;i<V;i++) {

        if(!vis[i]) {

            if(dfs(i,-1,vis,adj))
                return true;
        }
    }

    return false;
}

int main() {

    /*
        Component 1

            0 ----- 1
            |       |
            |       |
            3 ----- 2

        Cycle Present


        Component 2

            4 ----- 5

        No Cycle
    */

    int V = 6;

    vector<int> adj[V];

    // Component 1

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(0);
    adj[0].push_back(3);

    // Component 2

    adj[4].push_back(5);
    adj[5].push_back(4);

    if(isCycle(V,adj))
        cout << "Cycle Found\n";
    else
        cout << "No Cycle Found\n";

    return 0;
}