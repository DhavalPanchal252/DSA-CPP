#include <bits/stdc++.h>
using namespace std;

void optimal(vector<vector<int>> &a , int m , int n){ // TC : O(n^2) , SC : O(n^2)

    vector<int> ans;
    int left = 0 , right = n-1;
    int top = 0 , bottom = m-1;

    while(top <= bottom && left <= right){
        for(int i=left ; i<= right ; i++){
            ans.push_back(a[top][i]);
        }
        top++;

        for(int i = top ; i<= bottom ; i++){
            ans.push_back(a[i][right]);
        }
        right--;

        // edge case : 1D array then it ensure to print correct , OW it prints reverse ele at that point
        if(top <= bottom){
            
            for(int i = right ; i>= left ; i--){
                ans.push_back(a[bottom][i]);
            }
            bottom--;
        }
        
        if(left <= right){

            for(int i = bottom ; i>= top ; i--){
                ans.push_back(a[i][left]);
            }
            left++;
        }

    }
    
    for(auto &i : ans) cout << i << " ";

}

int main(){
    
    int m,n;
    cin >> m >> n ;

    vector<vector<int>> arr(m , vector<int> (n));
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            cin >> arr[i][j];
        }
    }

    optimal(arr,m,n);
    return 0;
}