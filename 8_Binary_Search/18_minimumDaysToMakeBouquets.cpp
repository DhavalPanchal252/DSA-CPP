#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &a , int day , int n , int m , int k){ // O(n)

    int cnt = 0 , bouquet = 0 ;

    for(int i=0 ; i<n ; i++){
        if(a[i] <= day){
            cnt++;
        }
        else{
            bouquet += (cnt/k);
            cnt = 0;
        }
    }
    bouquet += (cnt/k);
    if(bouquet >= m) return true;
    else return false;
}

int bruteForce(vector<int> &a , int n , int m , int k){// O((max-min)*n)
    
    if ((long long)m * k > n) return -1;

    int mini = *min_element(a.begin(),a.end());
    int maxi = *max_element(a.begin(),a.end());

    for(int i=mini ; i<=maxi ; i++){ // O(max-min)
        if(helper(a,i,n,m,k)) return i; // n
    }
    return -1;
}

int optimal(vector<int> &a , int n , int m , int k){// O(log(max-min)*n)

    if((long long)m*k > n) return -1;

    int mini = *min_element(a.begin(),a.end());
    int maxi = *max_element(a.begin(),a.end());

    int low = mini;
    int high = maxi;
    int ans = -1;
    while(low<=high){
        int mid = low + (high - low)/2;

        if(helper(a,mid,n,m,k)){
            ans = mid;
            high = mid-1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main(){
    
    int n , m , k;
    cin >> n >> m >> k;

    vector<int> a(n);

    for(auto &i : a) cin >> i;

    // cout << bruteForce(a,n,m,k);
    cout << optimal(a,n,m,k);
    return 0;
}