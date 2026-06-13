#include <bits/stdc++.h>
using namespace std;

/*
Non-overlapping Intervals

Given an array of intervals, return the minimum
number of intervals you need to remove so that
the remaining intervals do not overlap.

Two intervals overlap if:

current_start < previous_end
*/


/*
Greedy Approach

1. Sort intervals by ending time.
2. Always keep the interval that finishes earliest.
3. If the current interval overlaps with the
   previously selected interval, remove it.
4. Otherwise, keep it and update prevEnd.

TC : O(N log N)
     - Sorting the intervals

SC : O(1)
     - Ignoring sorting space
*/
int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a,
            const vector<int> &b) {

        return a[1] < b[1];
    });

    int removals = 0;

    int prevEnd = intervals[0][1];

    for(int i = 1; i < intervals.size(); i++) {

        // Overlap found
        if(intervals[i][0] < prevEnd) {

            removals++;
        }
        else {

            prevEnd = intervals[i][1];
        }
    }

    return removals;
}

int main() {

    int n;
    cin >> n;

    vector<vector<int>> intervals(n, vector<int>(2));

    for(int i = 0; i < n; i++) {
        cin >> intervals[i][0]
            >> intervals[i][1];
    }

    cout << eraseOverlapIntervals(intervals);

    return 0;
}