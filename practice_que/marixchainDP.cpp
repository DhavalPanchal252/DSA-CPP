#include <bits/stdc++.h>
using namespace std;

// Matrix Chain Multiplication using DP
int matrixChainMultiplication(vector<int> &d) {
    int n = d.size() - 1;        // number of matrices
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // dp[i][j] = minimum cost for multiplying Ai...Aj

    // length of chain (L = 2 to n)
    for (int L = 2; L <= n; L++) {
        for (int i = 1; i <= n - L + 1; i++) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;

            // Try all possible k (i ≤ k < j)
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k+1][j] + d[i-1] * d[k] * d[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {
    int n;
    cin >> n;

    // d array size = n+1
    // If matrices are A1 (d0×d1), A2 (d1×d2), ... An (d(n-1) × dn)
    vector<int> d(n+1);
    for (int i = 0; i <= n; i++)
        cin >> d[i];

    cout << matrixChainMultiplication(d) << endl;
    return 0;
}