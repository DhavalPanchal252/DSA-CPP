#include <bits/stdc++.h>
using namespace std;

/*
Minimum Platforms

Given arrival and departure times of trains
at a railway station, find the minimum number
of platforms required so that no train waits.

A platform cannot be shared if one train arrives
before another train departs.

Return the minimum number of platforms needed.
*/


// --------------------------------------------------
// Optimal Two Pointer Solution
// --------------------------------------------------
/*
Intuition:

1. Sort arrival times and departure times separately.
2. If the next train arrives before the earliest
   departure, we need one more platform.
3. Otherwise, a platform becomes free.

TC : O(N log N)
     - Sorting arrival and departure arrays

SC : O(1)
     - Ignoring sorting space
*/
int minPlatform(vector<int>& arr, vector<int>& dep) {

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 1;
    int j = 0;

    int platforms = 1;
    int maxPlatforms = 1;

    while(i < arr.size() && j < dep.size()) {

        // New train arrives before current train departs
        if(arr[i] <= dep[j]) {

            platforms++;
            i++;
        }
        else {

            // A platform gets free
            platforms--;
            j++;
        }

        maxPlatforms = max(maxPlatforms, platforms);
    }

    return maxPlatforms;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);
    vector<int> dep(n);

    for(auto &i : arr)
        cin >> i;

    for(auto &i : dep)
        cin >> i;

    cout << minPlatform(arr, dep);

    return 0;
}