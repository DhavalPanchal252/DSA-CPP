#include <bits/stdc++.h>
using namespace std;

// TC : O(n*m) , SC : O(n)
vector<int> bruteForce(vector<int> &a1,vector<int> &a2 ,int n,int m){

    vector<int> ans;// n

    for(auto &a : a1){ // n
        
        int i=0;
        while(i<m && a != a2[i]){ // m
            i++;
        }
        int greater = -1;
        for(int j=i+1 ; j<m ; j++){
            if(a < a2[j]){
                greater = a2[j];
                break;
            }   
        }
        ans.push_back(greater);
    }
    return ans;
}

// Monotonic Stack
// TC : O(2m + n*m) , SC : O(m + n)
vector<int> better(vector<int> &a1,vector<int> &a2 ,int n,int m){
    stack<int> st;
    vector<int> nge(m);// m

    for(int i=m-1 ; i>=0 ; i--){ // m
        while(!st.empty() && a2[i] >= st.top()){ // m
            st.pop();
        }
        if(!st.empty()) nge[i] = st.top();
        else nge[i] = -1;

        st.push(a2[i]);
    }

    vector<int> ans;// n
    for(auto &i : a1){ // n*m
        for(int j=0 ; j<m ; j++){
            if(i == a2[j]){
                ans.push_back(nge[j]);
            }
        }
    }
    return ans; 
}
// this better approach is good , but to find a1 ans it will takes O(n*m) so thats why we need optimal method which finds ans of a1 in O(m) times

// Monotonic Stack
// TC : O(2m + n) , SC : O(3m + n)
vector<int> optimal(vector<int> &a1,vector<int> &a2 ,int n,int m){
    stack<int> st;// m
    vector<int> nge(m);// m

    unordered_map<int,int> freq;//m

    for(int i=m-1 ; i>=0 ; i--){ // m
        while(!st.empty() && a2[i] >= st.top()){ // m
            st.pop();
        }
        if(!st.empty()){
            nge[i] = st.top();
            freq[a2[i]] = i;
        } 
        else{
            nge[i] = -1;
            freq[a2[i]] = i;
        } 

        st.push(a2[i]);
    }

    vector<int> ans;// n

    for(auto &i : a1){ // n
        ans.push_back(nge[freq[i]]);
    }
    return ans; 
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr1(n);
    for(auto &i : arr1) cin >> i;

    int m;
    cin >> m;

    vector<int> arr2(m);
    for(auto &i : arr2) cin >> i;

    // vector<int> ans = bruteForce(arr1,arr2,n,m);
    // vector<int> ans = better(arr1,arr2,n,m);
    vector<int> ans = optimal(arr1,arr2,n,m);

    for(auto &i : ans) cout << i << " ";

    return 0;
}