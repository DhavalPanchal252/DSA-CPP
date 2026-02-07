#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<vector<int>> &a , int m , int n){ // TC : O(n^2) , SC : O(n^2)

    vector<vector<int>> ans(m , vector<int>(n));

    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            ans[j][n-1-i] = a[i][j];
        }
    }

    // print
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

void optimal(vector<vector<int>> &a , int m , int n){// TC : O(n^2) , SC : O(1)

    // transpose the matrix
    for(int i=0 ; i<m-1 ;i++){
        for(int j=i+1 ; j<n ; j++){
            swap(a[i][j],a[j][i]);
        }
    }
    // reverse each row
    for(int i=0 ; i<m-1 ;i++){
        reverse(a[i].begin(), a[i].end());
    }

    // print
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
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

    // bruteForce(arr,m,n);
    optimal(arr,m,n);
    return 0;
}