#include <bits/stdc++.h>
using namespace std;
// possible ans is lie between max to sum of array
int helper(vector<int> &a, int capacity){ // O(n)
    int sum = 0 , cnt = 1;
    for(int i=0 ; i<a.size() ; i++){
        sum += a[i];
        if(sum > capacity)
        {
            sum = a[i];
            cnt++;
        }
    }
    return cnt;
}

int bruteForce(vector<int> &a, int days){ // TC : O((sum_weights - max_weight) * N) , SC : O(1)

    int maxVal = *max_element(a.begin(),a.end());
    for(int i=maxVal ; i<= accumulate(a.begin(),a.end(),0) ; i++){

        if(helper(a,i) <= days){ // n
            return i;
        }
    }
    return -1;
}

int optimal(vector<int> &a, int days){// TC : O(log(sum_weights - max_weight) * N) , SC : O(1)

    int low = *max_element(a.begin(),a.end());
    int high = accumulate(a.begin(),a.end(),0);
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        int help = helper(a,mid);

        if(help<=days){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;

}

int main(){

    int n ,days;
    cin >> n >> days;
    
    vector<int> a(n);
    

    for(auto &i : a) cin >> i;

    // cout << bruteForce(a,days);
    cout << optimal(a,days);

    return 0;
}
