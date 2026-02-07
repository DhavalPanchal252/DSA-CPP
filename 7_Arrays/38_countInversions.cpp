#include <bits/stdc++.h>
using namespace std;
// Brute Force
void bruteForce(vector<int> &a , int n ) {// TC : O(n^2) , SC : O(1)

    int cnt =0 ;
    for(int i=0 ; i< n ;i++){

        for(int j=i+1 ; j < n ; j++){

            if(a[i]>a[j]) cnt++;
        }
    }
    cout << cnt ;
}

// Optimal
int merged(vector<int> &a,int low,int mid,int high){

    vector<int> temp;
    int cnt = 0;
    int left = low;
    int right = mid+1;

    while(left <= mid && right <= high){
        if(a[left] > a[right]){
            temp.push_back(a[right]);
            cnt += (mid-left+1);
            right++;
        } 
        else {
            temp.push_back(a[left]);
            left++;
        }
    }
    while(left <= mid){
        temp.push_back(a[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(a[right]);
        right++;
    }

    for(int i = low ; i<=high ; i++){
        a[i] = temp[i-low];
    }
    return cnt;
}

int optimal(vector<int> &a ,int low, int high){ // TC : O(nlogn) , SC : O(n)

    int cnt = 0;

    if(low>=high) return cnt;

    int mid = (low+high)/2;

    cnt += optimal(a,low,mid);
    cnt += optimal(a,mid+1,high);
    cnt += merged(a,low,mid,high);

    return cnt;    
}

int main(){
    
    int n ;
    cin >> n;

    vector<int>  a(n);

    for(auto &i : a) cin >> i;

    // bruteForce(a,n);
    cout << optimal(a,0,n-1);
    return 0;
}