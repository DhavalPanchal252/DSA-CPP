#include <bits/stdc++.h>
using namespace std;
/*
TC : O(n) where n : no. activities ,only if end time is sorted ow O(nlogn)
SC : O(n) 
 */
int main(){
    
    int n;
    cin >> n;

    vector<pair<int,int>> activities(n);

    for(int i=0 ; i<n ; i++){

        cin >> activities[i].first >> activities[i].second;
    }

    int count = 1;
    int end_time = activities[0].second;

    for(int i=1 ; i<n ; i++){
        if(activities[i].first >= end_time){
            count++;
            end_time = activities[i].second;
        }
    }
    cout << count;
    return 0;
}