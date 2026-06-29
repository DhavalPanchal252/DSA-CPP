#include <bits/stdc++.h>
using namespace std;

/*
===========================================
        Accounts Merge

        Disjoint Set (DSU)

-------------------------------------------

Idea

1. Each account is a node.
2. If two accounts share an email,
   merge them.
3. Group emails using the
   ultimate parent.
4. Sort emails and build answer.

Time Complexity

O(N * M * α(N) + E log E)

N = Number of accounts
M = Average emails per account
E = Total unique emails

Space Complexity

O(N + E)

===========================================
*/

class DisjointSet {

    vector<int> parent, Size;

public:

    DisjointSet(int n) {

        parent.resize(n);
        Size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node) {

        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (Size[pu] < Size[pv]) {

            parent[pu] = pv;
            Size[pv] += Size[pu];
        }
        else {

            parent[pv] = pu;
            Size[pu] += Size[pv];
        }
    }
};

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

    int n = accounts.size();

    DisjointSet ds(n);

    unordered_map<string, int> emailToAccount;

    // Merge accounts having common emails

    for (int i = 0; i < n; i++) {

        for (int j = 1; j < accounts[i].size(); j++) {

            string email = accounts[i][j];

            if (emailToAccount.find(email) == emailToAccount.end()) {

                emailToAccount[email] = i;
            }
            else {

                ds.unionBySize(i, emailToAccount[email]);
            }
        }
    }

    // Emails grouped by parent account

    vector<vector<string>> mergedEmails(n);

    for (auto &it : emailToAccount) {

        string email = it.first;

        int parent = ds.findParent(it.second);

        mergedEmails[parent].push_back(email);
    }

    vector<vector<string>> ans;

    for (int i = 0; i < n; i++) {

        if (mergedEmails[i].empty())
            continue;

        sort(mergedEmails[i].begin(), mergedEmails[i].end());

        vector<string> temp;

        temp.push_back(accounts[i][0]);

        for (auto &email : mergedEmails[i])
            temp.push_back(email);

        ans.push_back(temp);
    }

    return ans;
}

int main() {

    /*
        Accounts

        John
        ├── johnsmith@mail.com
        └── john_newyork@mail.com

        John
        ├── johnsmith@mail.com
        └── john00@mail.com

        Mary
        └── mary@mail.com

        John
        └── johnnybravo@mail.com

        First two accounts share
        johnsmith@mail.com

        They are merged.
    */

    vector<vector<string>> accounts = {

        {"John","johnsmith@mail.com","john_newyork@mail.com"},
        {"John","johnsmith@mail.com","john00@mail.com"},
        {"Mary","mary@mail.com"},
        {"John","johnnybravo@mail.com"}
    };

    vector<vector<string>> ans = accountsMerge(accounts);

    cout << "Merged Accounts\n\n";

    for (auto &acc : ans) {

        for (auto &s : acc)
            cout << s << " ";

        cout << endl;
    }

    return 0;
}