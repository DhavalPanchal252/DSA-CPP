#include <bits/stdc++.h>
using namespace std;

/*
---------------------------------------------------------
M - Coloring Problem
---------------------------------------------------------

Given an undirected graph consisting of:

V vertices
E edges

Determine whether the graph can be colored
using at most m colors such that:

No two adjacent vertices
have the same color.

---------------------------------------------------------
Example:
---------------------------------------------------------

Input:

4 5

0 1
1 3
2 3
3 0
0 2

3

Output:

true

---------------------------------------------------------
Approach:
---------------------------------------------------------

1. Create adjacency list

2. Use backtracking

3. Try all colors from 1 to m
   for every node

4. Before assigning color:
      check whether adjacent nodes
      already contain same color

5. If safe:
      assign color
      recurse for next node

6. Backtrack if needed

---------------------------------------------------------
Base Case:
---------------------------------------------------------

If node == n

All nodes colored successfully

return true

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------

O(m^V)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------

O(V)

(color array + recursion stack)

---------------------------------------------------------
*/


class Solution {
public:

    bool isSafe(int node,
                int c,
                vector<vector<int>> &adj,
                vector<int> &color){

        for(auto &i : adj[node]){

            if(color[i] == c){

                return false;
            }
        }

        return true;
    }


    bool helper(int node,
                int n,
                int m,
                vector<int> &color,
                vector<vector<int>> &adj){

        // all nodes colored

        if(node == n){

            return true;
        }

        // try all colors

        for(int i = 1; i <= m; i++){

            if(isSafe(node, i, adj, color)){

                color[node] = i;

                if(helper(node + 1,
                          n,
                          m,
                          color,
                          adj)){

                    return true;
                }

                // backtrack

                color[node] = 0;
            }
        }

        return false;
    }


    bool graphColoring(int n,
                       vector<vector<int>> &edges,
                       int m){

        // adjacency list

        vector<vector<int>> adj(n);

        for(auto &i : edges){

            int u = i[0];
            int v = i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // color array

        vector<int> color(n, 0);

        return helper(0,
                      n,
                      m,
                      color,
                      adj);
    }
};


int main(){

    int n, e;

    cin >> n >> e;

    vector<vector<int>> edges;

    for(int i = 0; i < e; i++){

        int u, v;

        cin >> u >> v;

        edges.push_back({u, v});
    }

    int m;

    cin >> m;

    Solution obj;

    bool ans =
        obj.graphColoring(n, edges, m);

    if(ans){

        cout << "true";
    }
    else{

        cout << "false";
    }

    return 0;
}