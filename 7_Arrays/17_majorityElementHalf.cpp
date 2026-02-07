#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){ // O(n^2)

    for(int i=0 ; i<n ; i++){
        int count = 0 ;

        for(int j=0 ; j<n ; j++){
            if(a[i]==a[j]){
                count++;
            }
        }

        if(count >= int(n/2)){
            cout << a[i];
            break;
        }
    }
}

void better(vector<int> &a , int n){ // TC : O(n) SC : O(n)

    unordered_map<int , int> mapp; // O(1)

    for(int i=0 ; i<n ; i++){ // n
        mapp[a[i]]++;
    }

    for(auto &i : mapp ){ // n

        if( i.second >= int(n/2)){
            cout << i.first ;
        }
    }
}

// Boyer–Moore Majority Vote
void optimal(vector<int> &a , int n ){ // O(n)

    int count = 0 ;
    int ele ;
    // apply algo
    for(int i = 0 ; i<n ; i++){

        if(count == 0){
            ele = a[i];
            count++;
        }
        else if(ele == a[i]){
            count++;
        }
        else{
            count--;
        }
    }

    // check majority element
    int count1 = 0 ;

    for(int i=0 ; i<n ; i++){
        if(a[i] == ele){
            count1++;
        }
    }

    // print majority element
    if(count1 >= int(n/2)){
        cout << ele;
    }
}
int main(){
    
    int n ; 
    cin >> n;
    
    vector<int> arr(n);
    
    for(auto &i : arr){
        cin >> i ;
    }

    // bruteForce(arr , n);
    // better(arr , n);
    optimal(arr , n);
    return 0;
}