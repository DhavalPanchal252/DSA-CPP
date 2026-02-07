#include <bits/stdc++.h>
using namespace std;
// variety 2 : number of pos and neg are different
void bruteForce(vector<int> &a , int n){ // TC : O(n) + O(min(pos,neg)) +O(left), SC : O(n/2 + n/2) 
    vector<int> pos;
    vector<int> neg;

    for(int i=0 ; i<n ; i++){
        if(a[i]>=0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }

    if(pos.size()>neg.size()){
        for(int i=0 ; i< neg.size() ; i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = 2*neg.size();
        for(int i = neg.size() ; i < pos.size() ; i++){
            a[index] = pos[i];
            index++;
        }
    }
    else{
        for(int i=0 ; i< pos.size() ; i++){
            a[2*i] = pos[i];
            a[2*i+1] = neg[i];
        }
        int index = 2*pos.size();
        for(int i = pos.size() ; i < neg.size() ; i++){
            a[index] = neg[i];
            index++;
        }
    }
    

    for(int i=0 ; i<n ; i++){
        cout << a[i] << " ";
    }
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i ;

    bruteForce(arr,n);
    return 0;
}