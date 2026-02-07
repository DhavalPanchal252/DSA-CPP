#include <bits/stdc++.h>
using namespace std;
//  ceil : smallest  element SUCH THAT a[i] >= key then answer is a[i]
//  same as lower bound but , instead index we return element of that index
int bruteForce(vector<int> &a , int n , int key){ // TC : O(n) , SC : O(1)
    
    for(int i=0 ; i<n ; i++){

        if(a[i]>=key){
            return a[i];
        }
    }
    return -1; // No ceiling found
}

int optimal(vector<int> &a , int n , int key){ // TC : O(logn) , SC : O(1)

    int i = 0; 
    int j = n-1;
    int ceil_val = -1; // if not found then return -1
    while(i <= j){

        int mid = i + (j - i) / 2;

        if(a[mid] >= key){
            ceil_val = a[mid];
            j = mid - 1;
        }
        else{
            i = mid + 1;
        }
    }
    return ceil_val;

}

void STL(vector<int> &a , int n , int key){
    auto it = lower_bound(a.begin(), a.end(), key);
    if(it == a.end()){
        cout << -1; // Not found
    } else {
        cout << *it; // Ceil value
    }
}

int main(){

    int n ;
    cin >> n;

    vector<int> a(n);
    for(auto &i : a) cin >> i;

    int key;
    cin >> key;

    // cout << bruteForce(a,n,key);
    // cout << optimal(a,n,key);
    STL(a,n,key);
    
    return 0;
}