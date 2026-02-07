#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n , int k){ // O(n^3)

    int count = 0;
    for(int i = 0 ; i<n ; i++){
        
        for(int j=i ; j<n ; j++){
            int sum = 0;    
            for(int k=i ; k<=j ; k++){
                sum +=a[k];
            }
            if(sum == k){
                count++;
            }
        }
    }
    cout << count;
}


void better(vector<int> &a , int n , int k){ // O(n^2)

    int count = 0;
    for(int i = 0 ; i<n ; i++){
        int sum = 0;
        for(int j=i ; j<n ; j++){
            sum += a[j];
            if(sum == k){
                count++;
            }
        }
    }
    cout << count;
}

void optimal(vector<int> &a , int n , int k){ // O(n)
    unordered_map<int, int> mapp;
    int cnt = 0;
    int preSum = 0 ;
    mapp[0] = 1;
    for(int i=0 ; i<n ; i++){
        
        preSum += a[i];
        int remove = preSum - k ;

        cnt += mapp[remove];
        mapp[preSum] += 1; 
    }
    cout << cnt;
}

int main(){
    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a){
        cin >> i ;
    }

    int k; 
    cin >> k;
    // bruteForce(a,n,k);
    // better(a,n,k);
    optimal(a,n,k);
    return 0;
}