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
    map<int, int> mp;  // sorted map

    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }

    // Print frequency map
    for (auto it : mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    // Max/min frequency logic
    int maxFreq = 0;
    int minFreq = INT_MAX;
    int maxKey = -1;
    int minKey = -1;
    /*
    Value	Meaning	Use when...
    -1	"Not assigned yet"	Safer, clearer logic
    0	Can be valid key or default	Okay if key 0 is not used
    */

    for (auto it : mp) {
        if (it.second > maxFreq) {
            maxFreq = it.second;
            maxKey = it.first;
        }
        if (it.second < minFreq) {
            minFreq = it.second;
            minKey = it.first;
        }
    }

    cout << "Element with highest freq: " << maxKey << " (count: " << maxFreq << ")\n";
    cout << "Element with lowest freq: " << minKey << " (count: " << minFreq << ")\n";

    return 0;
}

