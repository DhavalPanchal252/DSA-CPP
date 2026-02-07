#include <bits/stdc++.h>
using namespace std;

void bruteforce(vector<int> a1,vector<int> a2) // O(n1*n2)
{
    int n1 = a1.size();
    int n2 = a2.size();

    vector<int> vis(n2,0);
    vector<int> ans;

    for(int i = 0 ; i<n1 ; i++){
        for (int j=0 ; j<n2 ; j++){

            if(a1[i]==a2[j] && vis[j]==0){
                ans.push_back(a1[i]);
                vis[j] = 1;
                break;
            }
            if(a2[j] > a1[i]){
                break;
            }
        }
    }

    for(auto &i : ans){
        cout << i << " ";
    }
}

void optimal(vector<int> a1 , vector<int> a2) // O(n1+n2)
{
    int n1 = a1.size();
    int n2 = a2.size();
    int i =0;
    int j =0;
    vector<int> ans;

    while(i<n1 && j<n2){
        if(a1[i] == a2[j]){
            ans.push_back(a1[i]);
            i++;
            j++;
        }
        else if(a1[i]>a2[j]){
            j++;
        }
        else if(a1[i]<a2[j]){
            i++;
        }
    }
    

    for(auto &i : ans){
        cout << i << " ";
    }
}

int main(){

    int n1;
    cin >> n1;
    vector<int> a1(n1);
    for(auto &i : a1){
        cin >> i;
    }

    int n2;
    cin >> n2;
    vector<int> a2(n2);
    for(auto &i : a2){
        cin >> i;
    }

    // bruteforce(a1,a2);

    optimal(a1,a2);
    return 0;
}
