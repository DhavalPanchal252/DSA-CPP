#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Course Schedule (LeetCode 207)

    Given:
    numCourses = V

    prerequisites = [a, b]

    Meaning:

        b -----> a

    To take course 'a',
    first complete course 'b'.

--------------------------------------------------

    Goal:

    Return true  -> All courses can be finished
    Return false -> Cycle exists

--------------------------------------------------

    Method 1 : DFS + Path Visited
    Method 2 : Kahn's Algorithm (BFS)

--------------------------------------------------

    Time Complexity : O(V + E)
    Space Complexity: O(V + E)

==================================================
*/


//==================================================
//          METHOD 1 : DFS Cycle Detection
//==================================================

bool dfs(int u,
         vector<vector<int>>& adj,
         vector<int>& vis,
         vector<int>& pathVis) {

    vis[u] = 1;
    pathVis[u] = 1;

    for (auto& v : adj[u]) {

        if (!vis[v]) {

            if (dfs(v, adj, vis, pathVis))
                return true;
        }

        else if (pathVis[v]) {

            return true;
        }
    }

    pathVis[u] = 0;

    return false;
}

bool canFinishDFS(int numCourses,
                  vector<vector<int>>& prerequisites) {

    int V = numCourses;

    vector<vector<int>> adj(V);

    // Build Graph

    for (auto& edge : prerequisites) {

        int course = edge[0];
        int prereq = edge[1];

        prereq -> course;

        adj[prereq].push_back(course);
    }

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            if (dfs(i,
                    adj,
                    vis,
                    pathVis))
                return false;
        }
    }

    return true;
}



//==================================================
//      METHOD 2 : Kahn's Algorithm (BFS)
//==================================================

bool canFinishBFS(int numCourses,
                  vector<vector<int>>& prerequisites) {

    int V = numCourses;

    vector<int> adj[V];

    // Build Graph

    for (auto& edge : prerequisites) {

        int course = edge[0];
        int prereq = edge[1];

        adj[prereq].push_back(course);
    }

    vector<int> indegree(V, 0);

    // Calculate Indegree

    for (int i = 0; i < V; i++) {

        for (auto& v : adj[i]) {

            indegree[v]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++) {

        if (indegree[i] == 0) {

            q.push(i);
        }
    }

    int count = 0;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        count++;

        for (auto& v : adj[node]) {

            indegree[v]--;

            if (indegree[v] == 0) {

                q.push(v);
            }
        }
    }

    return count == V;
}



//==================================================
//                     MAIN
//==================================================

int main() {

    /*
            Example 1

            0 ----> 1

            Can finish = YES
    */

    int numCourses = 2;

    vector<vector<int>> prerequisites = {

        {1,0}
    };

    cout << "Using DFS : ";

    if (canFinishDFS(numCourses,
                     prerequisites))
        cout << "Can Finish\n";
    else
        cout << "Cannot Finish\n";


    cout << "Using BFS : ";

    if (canFinishBFS(numCourses,
                     prerequisites))
        cout << "Can Finish\n";
    else
        cout << "Cannot Finish\n";



    /*
    ------------------------------------------------

    Example 2

    Uncomment to test

    numCourses = 2;

    prerequisites = {

        {1,0},
        {0,1}
    };

    Graph

        0 ----> 1
        ^       |
        |_______|

    Output

    DFS : Cannot Finish
    BFS : Cannot Finish

    ------------------------------------------------
    */

    return 0;
}