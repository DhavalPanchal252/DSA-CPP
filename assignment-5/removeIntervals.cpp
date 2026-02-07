#include <bits/stdc++.h>
using namespace std;
// TC : O(nlogn) and SC : O(1)
int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    // Step 1: Sort intervals by their end time
    sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int removeCount = 0;
    int prevEnd = INT_MIN;

    // Step 2: Traverse the intervals greedily
    for (int i = 0; i < n; i++) {
        int start = intervals[i].first;
        int end = intervals[i].second;

        if (start >= prevEnd) {
            // No overlap, keep this interval
            prevEnd = end;
        } else {
            // Overlapping interval, remove it
            removeCount++;
        }
    }

    cout << removeCount << endl;
    return 0;
}
