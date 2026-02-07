#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){ // TC :O(n^2) , SC : O(1)

    int maxLength = 0;

    for(int i=0 ; i<n ; i++){
        int sum = 0 ;
        int count=0;

        for(int j=i ; j<n ; j++){

            sum = sum + a[j];
            count++;
            if(sum == 0 ){
                maxLength = max(count , maxLength);
            }
        }
    }
    cout << maxLength;
}

void optimal(vector<int> &a , int n){ // TC :O(n) , SC : O(1)

    int maxLength = 0;

    unordered_map<int ,int> mapp;

    int sum = 0;
    for(int i=0 ; i<n ; i++){

        sum += a[i];

        if(sum == 0) 
            maxLength = i+1;
        else if(mapp.find(sum) != mapp.end()){
                maxLength = max(maxLength , i - mapp[sum]);
        }
        else{
            mapp[sum] = i;
        }
    }
    cout << maxLength;
}

int main(){
    
    int n ;
    cin >> n;

    vector<int> a(n);

    for(auto &i : a){
        cin >> i ;
    }

    // bruteForce(a,n);
    optimal(a,n);
    return 0;
}