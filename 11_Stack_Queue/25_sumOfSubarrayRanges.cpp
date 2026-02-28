// Sum of Subarray Ranges : max subarray sum - min subarray sum
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

// TC : O(n) , SC : O(1)
long long findMinimum(vector<int> &a , int n){

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
vector<int> findNme(vector<int> &a , int n){

    stack<int> st;
    vector<int> nme(n);

    for(int i=n-1 ; i>=0 ; i--){
        while(!st.empty() && a[i] >= a[st.top()]){
            st.pop();
        }

        nme[i] = st.empty() ? n : st.top();

        st.push(i);
    }
    return nme;
}

vector<int> findPmee(vector<int> &a , int n){

    stack<int> st;
    vector<int> pmee(n);

    for(int i=0 ; i<n ; i++){
        while(!st.empty() && a[i] > a[st.top()]){
            st.pop();
        }

        pmee[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return pmee;
}

// TC : O(n) , SC : O(1)
long long findMaximum(vector<int> &a , int n){

    long long sum = 0;
    vector<int> nme = findNme(a,n);
    vector<int> pmee = findPmee(a,n);

    for(int i=0 ; i<n ; i++){

        int left = i - pmee[i];
        int right = nme[i] - i;

        sum += left*right*1LL*a[i];
    }
    return sum;
}
long long optimal(vector<int> &a , int n){

    return findMaximum(a,n) - findMinimum(a,n);
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    cout << optimal(arr,n);
    return 0;
}