#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Course Schedule (DFS)

    Problem:

    There are V courses numbered
    from 0 to V-1.

    prerequisite = [a,b]

    means:

    b ---> a

    To take course 'a',
    first complete course 'b'.

--------------------------------------------------

    Observation:

    We can finish all courses
    if and only if the graph
    has NO cycle.

--------------------------------------------------

    Approach:

    Directed Graph Cycle Detection

    vis[node]
    -> Node has been visited

    pathVis[node]
    -> Node is currently in
       DFS recursion path

--------------------------------------------------

    Cycle Condition:

    If during DFS:

        pathVis[v] == 1

    then a back edge exists.

    Hence cycle exists.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V)

==================================================
*/

bool dfs(int src,
         vector<vector<int>>& adj,
         vector<int>& vis,
         vector<int>& pathVis) {

    vis[src] = 1;
    pathVis[src] = 1;

    for (auto& v : adj[src]) {

        if (!vis[v]) {

            if (dfs(v,
                    adj,
                    vis,
                    pathVis))
                return true;
        }

        else if (pathVis[v]) {

            return true;
        }
    }

    pathVis[src] = 0;

    return false;
}

bool canFinish(int numCourses,
               vector<vector<int>>& prerequisites) {

    int V = numCourses;

    vector<vector<int>> adj(V);

    // Build Graph

    for (auto& edge : prerequisites) {

        int course = edge[0];
        int prereq = edge[1];

        prereq -> course

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

int main() {

    /*
        Example 1

        numCourses = 2

        prerequisites

        [1,0]

        Graph

        0 ---> 1

        No Cycle

        Answer = true
    */

    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1,0}
    };

    if (canFinish(numCourses,
                  prerequisites))
        cout << "Can Finish All Courses\n";
    else
        cout << "Cannot Finish All Courses\n";

    return 0;
}