#include <bits/stdc++.h>
using namespace std;

vector<int> findNse(vector<int> &a , int n){

    stack<int> st;
    vector<int> nse(n);

    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && a[i] <= a[st.top()]){
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();

        st.push(i);
    }
    return nse;
}

vector<int> findPse(vector<int> &a , int n){

    stack<int> st;
    vector<int> pse(n);

    for(int i=0 ; i<n ; i++){
        while(!st.empty() && a[i] <= a[st.top()]){
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return pse;
}

// TC : O(n) , SC : O(n)
long long optimal(vector<int> &a , int n){

    long long maxi = INT_MIN;
    vector<int> nse = findNse(a,n);
    vector<int> pse = findPse(a,n);

    for(int i=0 ; i<n ; i++){

        long long sum = a[i] * 1LL * (nse[i] - pse[i] - 1);

        maxi = max(maxi,sum);
    }
    return maxi;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> hist(n);

    for(auto &i : hist) cin >> i;

    cout << optimal(hist,n);
    return 0;
}