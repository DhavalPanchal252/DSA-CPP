#include <bits/stdc++.h>
using namespace std;

/*
Job Sequencing Problem

You are given two arrays:
deadline[i] = deadline of ith job
profit[i]   = profit of ith job

Each job takes 1 unit of time.

A job earns profit only if it is completed
on or before its deadline.

Return:
1. Maximum number of jobs done
2. Maximum profit earned
*/


static bool comparator(const pair<int,int> &a,
                       const pair<int,int> &b) {

    // If profits are equal,
    // prefer smaller deadline
    if(a.second == b.second)
        return a.first < b.first;

    // Higher profit first
    return a.second > b.second;
}


/*
Greedy Approach

1. Sort jobs by profit in descending order.
2. For every job, try to schedule it at the
   latest available slot before its deadline.
3. If a slot is found, schedule the job.

TC : O(N log N + N^2)
     - O(N log N) for sorting
     - O(N^2) in worst case while searching slots

SC : O(N)
*/
vector<int> jobSequencing(vector<int> &deadline,
                          vector<int> &profit) {

    vector<pair<int,int>> jobs;

    for(int i = 0; i < deadline.size(); i++) {
        jobs.push_back({deadline[i], profit[i]});
    }

    sort(jobs.begin(), jobs.end(), comparator);

    int maxDeadline =
        *max_element(deadline.begin(), deadline.end());

    vector<int> slots(maxDeadline + 1, -1);

    int totalProfit = 0;
    int jobsDone = 0;

    for(auto &job : jobs) {

        int slot = job.first;

        while(slot > 0 && slots[slot] != -1) {
            slot--;
        }

        if(slot > 0) {

            slots[slot] = 1;

            totalProfit += job.second;
            jobsDone++;
        }
    }

    return {jobsDone, totalProfit};
}

int main() {

    int n;
    cin >> n;

    vector<int> deadline(n);
    vector<int> profit(n);

    for(auto &i : deadline)
        cin >> i;

    for(auto &i : profit)
        cin >> i;

    vector<int> ans =
        jobSequencing(deadline, profit);

    cout << "Jobs Done    : " << ans[0] << '\n';
    cout << "Total Profit : " << ans[1] << '\n';

    return 0;
}