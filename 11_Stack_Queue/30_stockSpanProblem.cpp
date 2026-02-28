#include <bits/stdc++.h>
using namespace std;

// TC : O(n^2) , SC : O(1)
vector<int> bruteForce(vector<int> &arr , int n){
    vector<int> ans;

    for(int i=0 ; i<n ; i++){

        int span = 0;
        for(int j=i ; j>=0 ; j--){
            if(arr[i] >= arr[j]) span++;
            else break;
        }
        ans.push_back(span);
    }
    return ans;

}

vector<int> findPge(vector<int> &arr , int n){
    vector<int> pge(n);

    stack<int> st;
    
    for(int i = 0 ; i<n ; i++){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        
        pge[i] = st.empty() ? -1 : st.top();
        
        st.push(i);
    }
    
    return pge;
}

// TC : O(n) , SC : O(n)
vector<int> optimal(vector<int> &arr , int n){
    vector<int> ans;
    vector<int> pge = findPge(arr,n);

    for(int i=0 ; i<n; i++){
        ans.push_back(i - pge[i]);
    }
    return ans;

}

int main(){
    
    int n;
    cin >> n ;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    // vector<int> ans = bruteForce(arr,n);
    vector<int> ans = optimal(arr,n);

    for(auto &i : ans) cout << i << " ";
    return 0;
}