#include <bits/stdc++.h>
using namespace std;

/*
Assign Cookies

You are given two integer arrays:

g[i] = greed factor of the ith child
s[j] = size of the jth cookie

A child can be satisfied if the cookie size is
greater than or equal to the child's greed factor.

Each child can get at most one cookie and each
cookie can be assigned to at most one child.

Return the maximum number of satisfied children.
*/


// TC : O(N log N + M log M)
// SC : O(1)
int findContentChildren(vector<int>& g, vector<int>& s) {

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int left = 0;
    int right = 0;
    int cnt = 0;

    while (left < g.size() && right < s.size()) {

        if (g[left] <= s[right]) {
            cnt++;
            left++;
        }

        right++;
    }

    return cnt;
}

int main() {

    int n;
    cin >> n;

    vector<int> g(n);

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int m;
    cin >> m;

    vector<int> s(m);

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    cout << findContentChildren(g, s);

    return 0;
}