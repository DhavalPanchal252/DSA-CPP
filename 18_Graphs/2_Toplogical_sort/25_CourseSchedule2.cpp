#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Course Schedule II (Kahn's Algorithm)

    Problem:

    There are V courses numbered
    from 0 to V-1.

    prerequisite = [a, b]

    means

        b -----> a

    First complete course b,
    then course a.

--------------------------------------------------

    Goal:

    Return one valid order in which
    all courses can be completed.

    If impossible (cycle exists),
    return an empty vector.

--------------------------------------------------

    Approach:

    1. Build graph.
    2. Calculate indegree.
    3. Push all nodes having
       indegree 0 into queue.
    4. Perform BFS.
    5. Store nodes in answer.
    6. If answer size != V,
       cycle exists.

--------------------------------------------------

    Time Complexity : O(V + E)

    Space Complexity: O(V + E)

==================================================
*/

vector<int> findOrder(int numCourses,
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

    // Push nodes having indegree 0

    for (int i = 0; i < V; i++) {

        if (indegree[i] == 0) {

            q.push(i);
        }
    }

    vector<int> order;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        order.push_back(node);

        for (auto& v : adj[node]) {

            indegree[v]--;

            if (indegree[v] == 0) {

                q.push(v);
            }
        }
    }

    // Cycle exists

    if (order.size() != V)
        return {};

    return order;
}

int main() {

    /*
            Example

            Courses = 4

            Prerequisites

            0 ----> 1
            0 ----> 2
            1 ----> 3
            2 ----> 3

            One Valid Order

            0 1 2 3
    */

    int numCourses = 4;

    vector<vector<int>> prerequisites = {

        {1,0},
        {2,0},
        {3,1},
        {3,2}
    };

    vector<int> ans =
        findOrder(numCourses,
                  prerequisites);

    if (ans.empty()) {

        cout << "No Valid Ordering (Cycle Exists)\n";
    }

    else {

        cout << "Course Order:\n";

        for (auto course : ans) {

            cout << course << " ";
        }

        cout << endl;
    }

    return 0;
}