#include <bits/stdc++.h>
using namespace std;

// TC : O(log(min(n,m))) , SC : O(1)
int optimal(vector<int> &a1, vector<int> &a2, int n, int m, int k){

    if(n > m) return optimal(a2, a1, m, n, k);

    int low = max(0, k - m);
    int high = min(k, n);

    while(low <= high){

        int mid1 = (low + high) / 2;
        int mid2 = k - mid1;

        int l1 = INT_MIN, r1 = INT_MAX;
        int l2 = INT_MIN, r2 = INT_MAX;
        
        if(mid1 < n) r1 = a1[mid1];
        if(mid1 - 1 >= 0) l1 = a1[mid1 - 1];

        if(mid2 < m) r2 = a2[mid2];
        if(mid2 - 1 >= 0) l2 = a2[mid2 - 1];

        if(l1 <= r2 && l2 <= r1){
            return max(l1, l2);
        }
        else if(l1 > r2){
            high = mid1 - 1;
        }
        else{
            low = mid1 + 1;
        }
    }
    return -1; // unreachable
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a1(n), a2(m);
    for (auto &i : a1) cin >> i;
    for (auto &i : a2) cin >> i;

    int k;
    cin >> k;

    cout << optimal(a1, a2, n, m, k) << endl;
    return 0;
}
