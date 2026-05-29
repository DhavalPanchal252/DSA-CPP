#include <bits/stdc++.h>
using namespace std;

// TC : O(N^2) , SC : O(1)
int bruteForce(string str){

    int n = str.size();
    int maxLen = 0;

    for(int i=0 ; i<n ; i++){
        
        vector<int> hashh(255,0);
        for(int j = i ; j < n ; j++){
            if(hashh[str[j]] == 1) break;

            maxLen = max(maxLen , j - i + 1);

            hashh[str[j]]++;
        }
    }

    return maxLen;
}

// TC : O(N) , SC : O(1)
int optimal(string str){

    int n = str.size();

    int l = 0 , r = 0 , maxLen = 0;

    vector<int> hashh(255,-1);

    while(r < n){

        if(hashh[str[r]] != -1){

            if(hashh[str[r]] >= l){
                l = hashh[str[r]] + 1;
            }
        }

        maxLen = max(maxLen , r - l + 1);

        hashh[str[r]] = r;
        r++;
    }

    return maxLen;
}
int main(){
    
    string str;

    getline(cin , str);

    // cout << bruteForce(str);
    cout << optimal(str);

    return 0;
}