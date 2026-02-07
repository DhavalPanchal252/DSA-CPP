#include <bits/stdc++.h>
using namespace std;

int atmostK(string s , int k){

    int left =0 , result = 0 ;
    unordered_map<char,int> freq;

    for(int right = 0 ; right < s.size() ; right++){

        freq[s[right]]++;

        while(k < freq.size()){
            freq[s[left]]--;

            if(freq[s[left]] == 0){
                freq.erase(s[left]);
            }
            left++;
        }
        result += (right - left + 1);
    }
    return result;
}

//  TC : O(n) , SC : O(1)
int optimal(string s , int k){

    return atmostK(s,k) - atmostK(s,k-1);
}

int main(){
    
    string s;
    cin >> s; 

    int k ;
    cin >> k;

    cout << optimal(s,k);
}