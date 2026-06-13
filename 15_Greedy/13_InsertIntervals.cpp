#include <bits/stdc++.h>
using namespace std;

/*
Insert Interval

You are given a list of non-overlapping intervals
sorted by their start times and a new interval.

Insert the new interval into the intervals and
merge overlapping intervals if necessary.

Return the resulting list of intervals.
*/


/*
TC : O(N)
     - Single traversal of intervals

SC : O(N)
     - Storing the answer
*/
vector<vector<int>> insertInterval(vector<vector<int>>& intervals,
                                   vector<int>& newInterval) {

    vector<vector<int>> ans;

    int n = intervals.size();
    int i = 0;

    // --------------------------------------------------
    // 1. Add all intervals completely before newInterval
    // --------------------------------------------------
    while(i < n && intervals[i][1] < newInterval[0]) {

        ans.push_back(intervals[i]);
        i++;
    }

    // --------------------------------------------------
    // 2. Merge all overlapping intervals
    // --------------------------------------------------
    while(i < n && intervals[i][0] <= newInterval[1]) {

        newInterval[0] =
            min(newInterval[0], intervals[i][0]);

        newInterval[1] =
            max(newInterval[1], intervals[i][1]);

        i++;
    }

    ans.push_back(newInterval);

    // --------------------------------------------------
    // 3. Add remaining intervals
    // --------------------------------------------------
    while(i < n) {

        ans.push_back(intervals[i]);
        i++;
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

    vector<int> newInterval(2);
    cin >> newInterval[0] >> newInterval[1];

    vector<vector<int>> ans =
        insertInterval(intervals, newInterval);

    for(auto &interval : ans) {
        cout << "[" << interval[0]
             << "," << interval[1]
             << "] ";
    }

    return 0;
}