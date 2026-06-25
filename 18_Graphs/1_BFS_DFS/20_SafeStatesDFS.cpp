#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Eventual Safe States (DFS)

    Definition:

    A node is called SAFE if every path
    starting from that node eventually
    ends at a terminal node.

--------------------------------------------------

    Terminal Node:

    A node having no outgoing edges.

--------------------------------------------------

    Key Idea:

    If a node is part of a cycle
    OR can reach a cycle,

    then it is NOT safe.

--------------------------------------------------

    DFS Arrays:

    vis[node]
    -> Node has been visited.

    pathVis[node]
    -> Node is currently in DFS path.

    check[node]
    -> 1 = Safe Node
       0 = Unsafe Node

--------------------------------------------------

    Cycle Detection:

    If during DFS:

        pathVis[v] == 1

    then a cycle exists.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

bool dfs(int u,
         vector<vector<int>>& graph,
         vector<int>& vis,
         vector<int>& pathVis,
         vector<int>& check) {

    vis[u] = 1;
    pathVis[u] = 1;

    for (auto& v : graph[u]) {

        if (!vis[v]) {

            if (dfs(v,
                    graph,
                    vis,
                    pathVis,
                    check))
                return true;
        }

        else if (pathVis[v]) {

            return true;
        }
    }

    pathVis[u] = 0;

    // Node is safe
    check[u] = 1;

    return false;
}

vector<int> eventualSafeNodes(
    vector<vector<int>>& graph) {

    int V = graph.size();

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);
    vector<int> check(V, 0);

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            dfs(i,
                graph,
                vis,
                pathVis,
                check);
        }
    }

    vector<int> ans;

    for (int i = 0; i < V; i++) {

        if (check[i] == 1)
            ans.push_back(i);
    }

    return ans;
}

int main() {

    /*
        Graph

        0 → 1
        ↓
        2

        1 → 2
        2 → 3
        3 → 4
        4 → 5
        5 → (Terminal)

        6 → 7
        7 → 6

        Cycle:
        6 ↔ 7

        Safe Nodes:
        0 1 2 3 4 5

        Unsafe Nodes:
        6 7
    */

    vector<vector<int>> graph = {

        {1,2},   // 0
        {2},     // 1
        {3},     // 2
        {4},     // 3
        {5},     // 4
        {},      // 5
        {7},     // 6
        {6}      // 7
    };

    vector<int> ans =
        eventualSafeNodes(graph);

    cout << "Safe Nodes: ";

    for (auto node : ans) {

        cout << node << " ";
    }

    cout << endl;

    return 0;
}