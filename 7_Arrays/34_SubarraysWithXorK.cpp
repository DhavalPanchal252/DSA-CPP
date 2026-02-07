#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n , int k){ // O(n^2)

    int cnt = 0 ;
    for(int i=0 ; i<n ; i++){

        int xorr =0 ;
        for(int j=i ; j<n ; j++){
            xorr ^= a[j];
            if(xorr == k){
                cnt++;
            }
        }
    }
    cout << cnt;
}

void optimal(vector<int> &a , int n , int k){ // O(n)

    unordered_map<int,int> mapp;
    mapp[0]=1;
    int cnt =0 ;
    int prefixXorr = 0;

    for(int i=0 ; i<n ; i++){
        // int xorr = x^k; 
        prefixXorr ^= a[i];
        int x = prefixXorr^k;

        if(mapp.find(x) != mapp.end()){
            cnt += mapp[x];
        }
        mapp[prefixXorr]++;
    }
    cout << cnt;
}
int main(){
    int n ; 
    cin >> n;

    vector<int> a(n);

    for(auto & i : a){
        cin >> i;
    }

    int k;
    cin >> k;

    // bruteForce(a, n , k);
    optimal(a, n , k);
    return 0;
}