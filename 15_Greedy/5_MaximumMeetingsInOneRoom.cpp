#include <bits/stdc++.h>
using namespace std;

/*
Maximum Meetings in One Room

Given two arrays:
s[i] = start time of ith meeting
f[i] = finish time of ith meeting

There is only one meeting room.

Find the maximum number of meetings that can be
performed without overlapping and return the
1-based indices of selected meetings in increasing order.
*/


static bool comparator(const pair<pair<int,int>,int> &a,
                       const pair<pair<int,int>,int> &b) {

    if(a.first.second == b.first.second)
        return a.second < b.second;

    return a.first.second < b.first.second;
}


/*
TC : O(N log N)
     - Sorting meetings by finish time

SC : O(N)
     - Storing meetings and answer
*/
vector<int> maxMeetings(vector<int> &s, vector<int> &f) {

    vector<pair<pair<int,int>,int>> meetings;

    for(int i = 0; i < s.size(); i++) {
        meetings.push_back({{s[i], f[i]}, i + 1});
    }

    sort(meetings.begin(), meetings.end(), comparator);

    vector<int> ans;

    int endTime = -1;

    for(auto &meeting : meetings) {

        int start = meeting.first.first;
        int finish = meeting.first.second;
        int idx = meeting.second;

        if(start > endTime) {

            ans.push_back(idx);
            endTime = finish;
        }
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> s(n);
    vector<int> f(n);

    for(auto &i : s) cin >> i;
    for(auto &i : f) cin >> i;

    vector<int> ans = maxMeetings(s, f);

    for(auto &i : ans) {
        cout << i << " ";
    }

    return 0;
}