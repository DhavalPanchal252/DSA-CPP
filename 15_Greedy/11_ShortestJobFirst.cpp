#include <bits/stdc++.h>
using namespace std;

/*
Shortest Job First (SJF)

Given the burst times of processes,
find the average waiting time if the
processes are executed using the
Shortest Job First scheduling algorithm.

Waiting Time:
A process waits until all previously
scheduled processes finish execution.

Return the floor value of the average
waiting time.
*/


/*
TC : O(N log N)
     - Sorting the burst times

SC : O(1)
     - Ignoring sorting space
*/
int averageWaitingTime(vector<int>& bt) {

    sort(bt.begin(), bt.end());

    long long currTime = 0;
    long long totalWaitingTime = 0;

    for(int i = 0; i < bt.size() - 1; i++) {

        currTime += bt[i];

        totalWaitingTime += currTime;
    }

    return totalWaitingTime / bt.size();
}

int main() {

    int n;
    cin >> n;

    vector<int> bt(n);

    for(auto &i : bt)
        cin >> i;

    cout << averageWaitingTime(bt);

    return 0;
}