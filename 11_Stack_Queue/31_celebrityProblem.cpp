#include <bits/stdc++.h>
using namespace std;

bool helper(vector<int> &arr , int self){

    for(int i=0 ; i<arr.size() ; i++){
        if(i == self) continue;
        else if(arr[i] != 0){
            return false;
        }
    }
    return true;
}
// TC : O(n^2) , SC : O(1)
int bruteForce(vector<vector<int>> &arr){

    for(int r=0 ; r < arr.size() ; r++){
        if(helper(arr[r],r)){

            bool know = true;

            for(int c=0 ; c < arr.size() ; c++){
                if(r != c && arr[c][r] == 0){
                    know = false;
                    break;
                }
            }
            if(know) return r;
        }
    }
    return -1;
}

// TC : O(n) , SC : O(1)
int optimal(vector<vector<int>> &arr){

    int top = 0;
    int bottom = arr.size()-1;

    while(top < bottom){
        if(arr[top][bottom] == 1) top++;
        else bottom--;
    }

    for(int i=0 ; i<arr.size() ; i++){
        if(i != top){
            if(arr[top][i] == 1 || arr[i][top] == 0) return -1;
        }
    }
    return top;
}

int main(){
    int n;
    cin >> n;
    
    vector<vector<int>> arr = {
        {0, 1, 1, 0}, 
        {0, 0, 0, 0}, 
        {1, 1, 0, 0}, 
        {0, 1, 1, 0}
    };

    // cout << bruteForce(arr);
    cout << optimal(arr);
    return 0;
}