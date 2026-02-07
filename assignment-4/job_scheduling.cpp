#include <bits/stdc++.h>
using namespace std;
// O(n log n + n × maxDeadline)≈O(n2)
// Space Complexity = O(n + maxDeadline)≈O(n) , n jobs
int main(){
    int n;
    cin >> n;
    
    vector<pair<int,int>> jobs(n);
    for(int i=0 ; i<n ; i++){
        cin >> jobs[i].first >> jobs[i].second;
    }

    // sort the jobs corresponding to profits

    sort(jobs.begin(),jobs.end(),[](auto &a , auto &b){
        return a.second > b.second;
    });

    // find the max deadline  
    int maxDeadline = 0;
    for(auto &job : jobs){
        maxDeadline = max(maxDeadline,job.first);
    }

    vector<int> slot(maxDeadline+1 , -1);

    int totalProfit = 0;

    for(auto &job : jobs){

        int deadline = job.first;
        int profit = job.second;

        for(int i = deadline ; i > 0 ; i--){

            if(slot[i] == -1){
                slot[i] = profit ;
                totalProfit += profit;
                break;
            }
        }
    }
    cout << totalProfit;
    return 0;
}