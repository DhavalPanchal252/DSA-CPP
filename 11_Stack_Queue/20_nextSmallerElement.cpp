// same as next greatest element
#include <bits/stdc++.h>
using namespace std;

// TC : O(n*n) , SC : O(n)
vector<int> bruteForce(vector<int> &a1,int n){

    vector<int> ans;// n

    for(int i = 0 ; i<n ; i++){ // n
        int smallest = -1;
        for(int j = i+1 ; j< n ; j++){ // n

            if(a1[i] > a1[j]){
                smallest = a1[j];
                break;
            }
        }
        ans.push_back(smallest);
    }
    return ans;
}

// TC : O(3n) , SC : O(2n)
vector<int> optimal(vector<int> &a1,int n){

    vector<int> ans(n);// n'
    stack<int> st;//n

    for(int i = n-1 ; i>=0 ; i--){//2n + n

        while(!st.empty() && a1[i] <= st.top()){ // n
            st.pop();
        }

        
        ans[i] = st.empty() ? -1 : st.top();
       
        st.push(a1[i]);
    }
    return ans;
}
int main(){
    
    int n;
    cin >> n;

    vector<int> arr1(n);
    for(auto &i : arr1) cin >> i;

    // vector<int> ans = bruteForce(arr1,n);
    vector<int> ans = optimal(arr1,n);

    for(auto &i : ans) cout << i << " ";

    return 0;
}