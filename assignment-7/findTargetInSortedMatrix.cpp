#include <bits/stdc++.h>
using namespace std;
// TC : O(mlogn) and SC : O(1)
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int target;
    cin >> target;

    for(int i = 0; i < m; i++) {
        
        if(target >= matrix[i][0] && target <= matrix[i][n-1]) { // If target could be in this row, do binary search
            int l = 0, r = n - 1;
            while(l <= r) {
                int mid = l + (r - l) / 2;
                if(matrix[i][mid] == target) {
                    cout << "true";
                    return 0;
                }
                else if(matrix[i][mid] < target) l++;
                else r--;
            }
        }
    }

    cout << "false";
    return 0;
}
