#include <bits/stdc++.h>
using namespace std;

void bruteforce(vector<int> &a , int n){ // O(N^2)
    for(int i=1 ; i<=n ; i++){
        int flag = 0;

        for(int j=0 ; j<n-1 ; j++){
            if(a[j] == i){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            cout << i;
        }
    }
}

void better(vector<int> &a , int n){ // O(2N) and SC O(N)

    map<int,int> mpp;

    for(int i=0 ; i<n-1 ; i++){
        mpp[a[i]] = 1;
    }
    for(int i=1 ; i<=n ; i++){
        if(mpp[i] == 0){
            cout << i;
        }
    }
}

void optimal1(vector<int> &a , int n){ // O(N)
    int sum = n*(n+1)/2;
    int sum1 = 0;
    for(int i = 0 ; i<n-1 ; i++){
        sum1 += a[i];
    }

    cout << sum-sum1;
}

void optimal2(vector<int> &a , int n){

    int xor1 = 0;
    int xor2 = 0;
    int N = n-1;
    for(int i=0 ; i<N ; i++){
        xor2 ^= a[i];
        xor1 ^= (i+1);
    }
    xor1 ^= n;

    cout << (xor1^xor2);
}

int main(){
    
    int n ;
    cin >> n;
    vector<int> a(n);

    for(auto &i : a){
        cin >> i;
    }

    // bruteforce(a,n);
    // better(a,n);
    // optimal1(a,n);
    optimal2(a,n);
    return 0;
}