#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n , int k){ // O(n^2)

    for(int i=0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){

            int sum = a[i]+a[j];

            if(sum == k){
                cout << "yes";
                return;
            }
        }
    }
    cout << "No";
}

void better(vector<int> &a , int n , int k){ // TC : O(n) and SC : O(n)

    unordered_map<int,int> mapp; // O(1) avg case but , O(n) worst case... O(1) like 99.9% of the time." 

    for(int i = 0; i < n; i++){

        int complement = k - a[i];

        if(mapp.find(complement) != mapp.end()){
            cout << "Yes" << endl;
            cout << mapp[complement] <<" " << i; // index of two element
            return;
        }

        mapp[a[i]] = i; // store current element
    }

    cout << "No";
}

void optimal(vector<int> &a , int n , int k){ // TC : O(nlogn) and SC : O(1)
    int i = 0 ;
    int j = n-1;
    int sum = 0;

    sort(a.begin() , a.end()); // nlogn

    while(i<j){
        sum = a[i]+a[j];

        if(sum < k){
            i++;
        }
        else if(sum > k){
            j--;
        }
        else{
            cout << "Yes";
            return;
        }
    }
    cout << "No";
}
int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr){
        cin >> i; 
    }

    int k;
    cin >> k;
 
    // bruteForce(arr , n , k);
    better(arr , n , k);
    // optimal(arr , n , k);
 
    return 0;
}