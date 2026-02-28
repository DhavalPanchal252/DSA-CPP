#include <bits/stdc++.h>
using namespace std;

// TC : O(n*n) , SC : O(1)
long long bruteForce(vector<int> &a , int n){

    long long sum = 0;

    for(int i=0 ; i<n; i++){ // n
        int mini = a[i];

        for(int j=i ; j<n ; j++){ // n
            mini = min(mini,a[j]);
            sum += mini;
        }
    }
    return sum;
}

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

vector<int> findPsee(vector<int> &a , int n){

    stack<int> st;
    vector<int> psee(n);

    for(int i=0 ; i<n ; i++){
        while(!st.empty() && a[i] < a[st.top()]){
            st.pop();
        }

        psee[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return psee;
}

// TC : O(n) , SC : O(n)
long long optimal(vector<int> &a , int n){

    long long sum = 0;
    vector<int> nse = findNse(a,n);
    vector<int> psee = findPsee(a,n);

    for(int i=0 ; i<n ; i++){

        int left = i - psee[i];
        int right = nse[i] - i;

        sum += left*1LL*right*a[i];
    }
    return sum;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    cout << bruteForce(arr,n);
    // cout << optimal(arr,n);
    return 0;
}