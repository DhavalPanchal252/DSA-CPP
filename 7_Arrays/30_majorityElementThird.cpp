#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<int> &a , int n){ // TC : O(n^2) SC : O(1)
    
    vector<int> result; // list can have at most 2 elements 

    for(int i=0 ; i<n ; i++){

        if(result.empty() || result[0] != a[i]){

            int count = 0 ;
            for(int j=0 ; j<n ; j++){
                if(a[i]==a[j]){
                    count++;
                }
            }

            if(count > int(n/3)){
                result.push_back(a[i]);
            }
        }
        if(result.size() == 2) break;
            
    }

    for(auto &i : result) cout << i << " ";
}

void better(vector<int> &a , int n){ // TC : O(n) SC : O(n)

    unordered_map<int , int> mapp; // O(1)
    vector<int> result;

    for(int i=0 ; i<n ; i++){ // n
        mapp[a[i]]++;
    }

    for(auto &i : mapp ){ // n

        if( i.second > int(n/3)){
            result.push_back(i.first);
        }
    }

    for(auto &i : result ){ // constant
       cout << i << " "; 
    }
}

// Boyer–Moore Majority Vote
void optimal(vector<int> &a , int n ){ // O(n)

    vector<int> result;

    int count1 = 0 , count2 = 0;
    int ele1 , ele2 ;
    // apply algo
    for(int i = 0 ; i<n ; i++){

        if(count1 == 0 && a[i] != ele2){
            ele1 = a[i];
            count1++;
        }
        else if(count2 == 0 && a[i] != ele1){
            ele2 = a[i];
            count2++;
        }
        else if(ele1 == a[i]) count1++ ;
        else if(ele2 == a[i]) count2++ ;
        else{
            count1--;
            count2--;
        }
    }

    // check majority element
    int cnt1 = 0 ;
    int cnt2 = 0 ;

    for(int i=0 ; i<n ; i++){
        if(a[i] == ele1){
            cnt1++;
        }
        if(a[i] == ele2){
            cnt2++;
        }
    }

    if(ele1 == ele2){ // edge case if all element are same then ele1 == ele2 , so its stores in result duplicate
        if(cnt1 > int(n/3)) result.push_back(ele1);
    }
    else{
        if(cnt1 > int(n/3)) result.push_back(ele1);
        if(cnt2 > int(n/3)) result.push_back(ele2);
    }
    
    // print majority element
    for(auto &i : result) cout << i << " ";
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