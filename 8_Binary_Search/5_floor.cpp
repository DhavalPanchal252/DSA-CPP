#include <bits/stdc++.h>
using namespace std;
//  floor : Greatest  element SUCH THAT a[i] <= key then answer is a[i]
int bruteForce(vector<int> &a , int n , int key){ // TC : O(n) , SC : O(1)
    
    for(int i=n-1 ; i>=0 ; i--){

        if(a[i]<=key){
            return a[i];
        }
    }
    return 0;
}

int optimal(vector<int> &a , int n , int key){ // TC : O(logn) , SC : O(1)

    int i =0  ; 
    int j = n-1;
    int lower = 0; // if not found then it would be last index
    while(i<=j){

        int mid = i + (j-i)/2;

        if(a[mid] <= key){
            lower = a[mid];
            i = mid+1;
        }
        else{
            j = mid-1;
        }
    }
    return lower;

}

void STL(vector<int> &a , int n , int key){
    auto it = upper_bound(a.begin(), a.end(), key);
    
    if(it == a.begin()){
        cout << -1; // No element <= key
    } else {
        --it;
        cout << *it; // Floor value
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