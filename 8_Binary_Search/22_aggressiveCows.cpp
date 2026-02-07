#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &a, int cows , int dist)
{ 
    int c1 = a[0]; 
    int cnt = 1; 
    for(int i=1 ; i<a.size() ; i++){ 
        int c2 = a[i]; 
        if(c2-c1 >= dist)
        { 
            cnt++; 
            c1= c2; 
        } 
    } 
    return (cnt >= cows);
}
// TC : O(nlogn) + O((maxEle - minEle)*n)
int bruteForce(vector<int> &a, int cows){ 

    sort(a.begin(), a.end());
    int ans = -1;
    // int high = *max_element(a.begin(),a.end()) - *min_element(a.begin(),a.end());
    int high = a.back() - a.front();
    for(int i=1 ; i<=high ; i++){
        if(helper(a,cows,i)){
            ans = i;
        }
        else break;
    }
    return ans;
}

// TC : O(nlogn) + O(log(maxEle - minEle)*n)
int optimal(vector<int> &stalls, int cows){

    sort(stalls.begin(), stalls.end());

    int low = 0;
    // int high = *max_element(stalls.begin(),stalls.end()) - *min_element(stalls.begin(),stalls.end());
    // or
    int high = stalls.back() - stalls.front();
    int ans = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;

        if(helper(stalls, cows, mid)){
            ans = mid;
            low = mid + 1;   // try larger minimum distance
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){

    int n ,cows;
    cin >> n >> cows;
    
    vector<int> a(n);
    

    for(auto &i : a) cin >> i;

    cout << bruteForce(a,cows);
    // cout << optimal(a,cows);

    return 0;
}
