#include <bits/stdc++.h>
using namespace std;

/*
==================================================
            Alien Dictionary

        (Topological Sort - Kahn's Algorithm)

--------------------------------------------------

Problem:

Given a sorted dictionary of an alien language,
find one valid order of the characters.

--------------------------------------------------

Idea:

Compare every adjacent pair of words.

The first different character determines
the ordering.

Example:

abcd
abef

First different character:

c -> e

Create edge:

c -----> e

--------------------------------------------------

After building the graph,

Perform Kahn's Algorithm
(BFS Topological Sort).

If all characters are processed,
return the order.

Otherwise,
return "".

--------------------------------------------------

Time Complexity :

Building Graph : O(N * L)

Topological Sort : O(V + E)

Overall : O(N * L + V + E)

--------------------------------------------------

Space Complexity :

O(V + E)

==================================================
*/

string findOrder(vector<string> &words) {

    const int K = 26;

    vector<int> adj[K];

    vector<int> present(K, 0);

    // Mark all characters present

    for (auto &word : words) {

        for (auto &ch : word) {

            present[ch - 'a'] = 1;
        }
    }

    // Build Graph

    for (int i = 0; i < words.size() - 1; i++) {

        string first = words[i];
        string second = words[i + 1];

        int len = min(first.size(), second.size());

        bool found = false;

        for (int j = 0; j < len; j++) {

            if (first[j] != second[j]) {

                int u = first[j] - 'a';
                int v = second[j] - 'a';

                // Avoid duplicate edge

                bool exists = false;

                for (auto &x : adj[u]) {

                    if (x == v) {

                        exists = true;
                        break;
                    }
                }

                if (!exists)
                    adj[u].push_back(v);

                found = true;
                break;
            }
        }

        // Invalid dictionary

        if (!found && first.size() > second.size())
            return "";
    }

    vector<int> indegree(K, 0);

    // Calculate Indegree

    for (int i = 0; i < K; i++) {

        for (auto &v : adj[i]) {

            indegree[v]++;
        }
    }

    queue<int> q;

    // Push all characters having indegree 0

    for (int i = 0; i < K; i++) {

        if (present[i] && indegree[i] == 0) {

            q.push(i);
        }
    }

    string order = "";

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        order.push_back(node + 'a');

        for (auto &v : adj[node]) {

            indegree[v]--;

            if (indegree[v] == 0) {

                q.push(v);
            }
        }
    }

    int totalChars = 0;

    for (int i = 0; i < K; i++) {

        totalChars += present[i];
    }

    if (order.size() != totalChars)
        return "";

    return order;
}

int main() {

    /*
        Dictionary

        baa
        abcd
        abca
        cab
        cad

        Edges

        b -> a
        d -> a
        a -> c
        b -> d

        One Valid Order

        b d a c
    */

    vector<string> words = {

        "baa",
        "abcd",
        "abca",
        "cab",
        "cad"
    };

    string ans = findOrder(words);

    if (ans.empty()) {

        cout << "Invalid Dictionary\n";
    }

    else {

        cout << "Alien Dictionary Order:\n";
        cout << ans << endl;
    }

    return 0;
}