#include <bits/stdc++.h>
using namespace std;

void bruteForce(vector<vector<int>> &a , int m , int n){ // TC : O(m * n * (m + n))
    for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If current cell is zero
                if (a[i][j] == 0) {
                    // Mark all elements in this row as -1 (except existing zeros)
                    for (int col = 0; col < n; col++) {
                        if (a[i][col] != 0)
                            a[i][col] = -1;
                    }
                    // Mark all elements in this column as -1 (except existing zeros)
                    for (int row = 0; row < m; row++) {
                        if (a[row][j] != 0)
                            a[row][j] = -1;
                    }
                }
            }
    }

        // Second pass: replace all -1 markers with 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -1)
                a[i][j] = 0;
        }
    }
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
}


void better(vector<vector<int>> &a , int m , int n){ // TC :O(2mn) , SC :O(m)+O(n)

    vector<int> rows(m,0);
    vector<int> cols(n,0);
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            if(a[i][j] == 0){
                
                rows[i] =1 ;
                cols[j] =1 ;   
            }
        }
    }

    for(int i=0 ; i<m ; i++){
        for(int j=0 ; j<n ;j++){
            
            if(rows[i] || cols[j]){
                a[i][j]=0;
            }
        }
    }
    // print
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void optimal(vector<vector<int>> &a , int m , int n){//TC : O(mn) , SC : O(1)
    // vector<int> rows(m,0); -> a[0][...]
    // vector<int> cols(n,0); -> a[...][0]
    int col0 = 1;
    for(int i=0 ; i<m ;i++){
        for(int j=0 ; j<n ; j++){
            if(a[i][j] == 0){
                // mark i-th row
                a[i][0] = 0 ;
                // mark j-th col
                if(j!=0)
                    a[0][j] = 0 ;   
                else 
                    col0 = 0 ;
            }
        }
    }

    for(int i=1 ; i<m ;i++){
        for(int j=1 ; j<n ; j++){
            if(a[i][0] == 0 || a[0][j] == 0){
                a[i][j]=0;
            }
        }
    }

    if(a[0][0] == 0){
        for(int j=0 ; j<n ;j++) a[0][j] = 0;
    }

    if(col0 == 0){
        for(int i=0 ; i<m ;i++) a[i][0] = 0;
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
    // better(arr,m,n);
    optimal(arr,m,n);
    return 0;
}