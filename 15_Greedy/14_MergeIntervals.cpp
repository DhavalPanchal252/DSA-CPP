#include <bits/stdc++.h>
using namespace std;

/*
Merge Intervals

Given an array of intervals where:

intervals[i] = [starti, endi]

Merge all overlapping intervals and return
the resulting non-overlapping intervals.
*/


/*
TC : O(N log N)
     - Sorting the intervals

SC : O(N)
     - Storing the merged intervals
*/
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

    vector<vector<int>> ans;

    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    for(auto &interval : intervals) {

        // No overlap
        if(ans.empty() || ans.back()[1] < interval[0]) {

            ans.push_back(interval);
        }
        else {

            // Merge with previous interval
            ans.back()[1] = max(ans.back()[1], interval[1]);
        }
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<vector<int>> ans =
        mergeIntervals(intervals);

    for(auto &interval : ans) {

        cout << "[" << interval[0]
             << "," << interval[1]
             << "] ";
    }

    return 0;
}