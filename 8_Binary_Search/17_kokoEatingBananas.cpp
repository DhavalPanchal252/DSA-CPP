#include <bits/stdc++.h>
using namespace std;
// possible ans is lie between 1 to max value of array
long long helper(vector<int> &a, int hourly){
    long long total = 0;
    for(int i=0 ; i<a.size() ; i++){
        total += ceil((double)a[i]/(double)hourly);
    }
    return total;
}

int bruteForce(vector<int> &a, int h){ // TC : O(maxVal * n) , SC : O(1)

    int maxVal = *max_element(a.begin(),a.end());
    for(int i=1 ; i<= maxVal ; i++){

        if(helper(a,i) <= h){
            return i;
        }
    }
    return maxVal;
}

int optimal(vector<int> &a, int h){// TC : O(log(maxVal) * n) , SC : O(1)

    int low = 1;
    int high = *max_element(a.begin(),a.end());
    int ans = INT_MIN;

    while(low<=high){

        int mid = low + (high-low)/2;

        if(helper(a,mid) <= h){
            ans = mid;
            high  = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    
    for(auto &i : a) cin >> i;

    int h ;
    cin >> h;

    // cout << bruteForce(a,h);
    cout << optimal(a,n);

    return 0;
}
