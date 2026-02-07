#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N!*N), since we are generating all possible permutations, it takes N! time.
// Space Complexity: O(N!), storing all permutations.
void bruteForce(vector<int> &a , int n){

    next_permutation(a.begin(), a.end() );

    for(auto i : a) cout << i << " ";
}

void optimal(vector<int> &a , int n){ // O(3n)

    int index = -1;
    for(int i= n-2 ; i>=0 ; i--){
        if(a[i]<a[i+1]){
            index = i; 
            break;
        }
    }

    if(index == -1){
        reverse(a.begin(),a.end());
        for(auto &i : a){
            cout << i << " ";
        }
        return;
    }
    for(int i= n-1 ; i>=index ; i--){
        if(a[i]>a[index]){
            swap(a[i],a[index]);
            break;
        }
    }
    reverse(a.begin() + index + 1,a.end());
    for(auto &i : a){
        cout << i << " ";
    }

}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i ;

    bruteForce(arr,n);
    // optimal(arr,n);
    return 0;
}