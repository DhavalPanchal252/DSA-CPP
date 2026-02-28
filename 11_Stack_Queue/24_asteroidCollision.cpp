#include <bits/stdc++.h>
using namespace std;

vector<int> optimal(vector<int> &a,int n){

    stack<int> st;
    vector<int> ans;

    for(auto &i : a){
        if(i>0) st.push(i);
        else{
            while(!st.empty() && st.top()>0 && st.top() < abs(i)){
                st.pop();
            }

            if(!st.empty() && st.top() == abs(i)) st.pop();

            else if(st.empty() || st.top()<0) st.push(i);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    vector<int> ans = optimal(arr,n);

    for(auto &i : ans) cout << i << " ";
    return 0;
}