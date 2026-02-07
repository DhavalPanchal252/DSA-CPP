#include <bits/stdc++.h>
using namespace std;
//  lower bound : SMALLERST INDEX SUCH THAT a[i] >= key then answer is i 
int bruteForce(vector<int> &a , int n , int key){ // TC : O(n) , SC : O(1)
    
    for(int i=0 ; i<n ; i++){

        if(a[i]>=key){
            return i;
        }
    }
    return n;
}

int optimal(vector<int> &a , int n , int key){ // TC : O(logn) , SC : O(1)

    int i =0  ; 
    int j = n-1;
    int lower = n; // if not found then it would be last index
    while(i<=j){

        int mid = i + (j-i)/2;

        if(a[mid] >= key){
            lower = mid;
            j = mid-1;
        }
        else{
            i = mid+1;
        }
    }
    return lower;

}

void STL(vector<int> &a , int n , int key){
    int lower = lower_bound(a.begin(),a.end(),key) - a.begin();
    cout << lower;
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