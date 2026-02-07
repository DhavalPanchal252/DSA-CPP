#include <bits/stdc++.h>
using namespace std;

// TC : O(n^2) , SC : O(n)
void bruteForce(vector<vector<int>> &interval , int n){

    vector<vector<int>> result;
    
    sort(interval.begin(),interval.end());

    for(int i=0 ; i<n ; i++){
        int start = interval[i][0];
        int end = interval[i][1];

        for(int j=i+1 ; j<n ; j++){
            if(interval[j][0] <= end){
                end = max(end , interval[j][1]);
                i = j;
            }
        }
        result.push_back({start,end});
        
    }

    for(auto &i : result){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

// TC : O(nlogn) , SC : O(n)
void optimal(vector<vector<int>> &interval , int n){
    
    sort(interval.begin(),interval.end()); // nlogn

    vector<vector<int>> result;
    result.reserve(interval.size());

    for(auto i : interval){ // n
        if(result.empty() || result.back()[1] < i[0]){
            result.push_back(i);
        }
        else{
            result.back()[1] = max(result.back()[1] , i[1]);
        }
    }

    for(auto &i : result){
        for(auto &j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}

int main(){
    int n ;
    cin >> n;

    vector<vector<int>> interval(n,vector<int>(2));

    for(auto &i : interval){
        for(auto &j : i){
            cin >> j;
        }
    }

    // bruteForce(interval,n);
    optimal(interval,n);
    
    // for(auto &i : interval){
    //     for(auto &j : i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}