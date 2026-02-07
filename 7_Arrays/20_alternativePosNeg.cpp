#include <bits/stdc++.h>
using namespace std;
// variety 1 : number of pos and neg are same
void bruteForce(vector<int> &a , int n){ // TC : O(n + n/2) , SC : O(n/2 + n/2) 
    vector<int> pos;
    vector<int> neg;

    for(int i=0 ; i<n ; i++){
        if(a[i]>=0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    for(int i=0 ; i< n/2 ; i++){
        a[2*i] = pos[i];
        a[2*i+1] = neg[i];

    }

    for(int i=0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}

void optimal(vector<int> &a , int n){ // TC : O(n) , SC : O(n)
    vector<int> ans(n);
    int pos = 0,neg = 1;
    for(int i=0 ; i<n ; i++){
        if(a[i] > 0 ){
            ans[pos] = a[i];
            pos +=2;
        }
        else{
            ans[neg] = a[i];
            neg += 2;
        }

    }
    for(auto &i : ans){
        cout << i << " ";
    }
}
int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i ;

    // bruteForce(arr,n);
    optimal(arr,n);
    return 0;
}