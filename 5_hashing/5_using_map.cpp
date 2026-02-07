#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Precompute frequencies
    
    // map<int, int> mp;  // sorted ordered
    unordered_map<int, int> mp; // unsorted ordered
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }

     // iterate over the map:
    for(auto it : mp){
        cout << it.first << "->" << it.second << endl; // gives sorted ordered
    }
    


    int q;
    cin >> q;

    while (q--) {
        int num;
        cin >> num;
        cout << mp[num] << endl;
    }

    return 0;
}
