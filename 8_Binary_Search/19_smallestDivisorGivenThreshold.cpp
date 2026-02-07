#include <bits/stdc++.h>
using namespace std;
// possible ans is lie between 1 to max value of array
int helper(vector<int> &a, int div){ // O(n)
    int sum = 0;
    for(int i=0 ; i<a.size() ; i++){
        sum += ceil((double)a[i]/(double)div);
    }
    return sum;
}

int bruteForce(vector<int> &a, int threshold){ // TC : O(maxVal * n) , SC : O(1)

    int maxVal = *max_element(a.begin(),a.end());
    for(int i=1 ; i<= maxVal ; i++){

        if(helper(a,i) <= threshold){ // n
            return i;
        }
    }
    return -1;
}

int optimal(vector<int> &a, int threshold){

    if(a.size() > threshold) return -1;
    int low = 1;
    int high = *max_element(a.begin(), a.end() );
    int ans = -1;

    while(low<=high){
        int mid = low + (high - low)/2;

        int help = helper(a,mid);

        if(help<=threshold){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    return ans;

}

int main(){

    int n;
    cin >> n;
    vector<int> a(n);
    
    int threshold ;
    cin >> threshold;

    for(auto &i : a) cin >> i;

    cout << bruteForce(a,threshold);
    // cout << optimal(a,threshold);

    return 0;
}
