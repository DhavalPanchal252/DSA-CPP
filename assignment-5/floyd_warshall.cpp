#include <bits/stdc++.h>
using namespace std;

//  TC : O(n^3) and SC : O(n^2)  
/*
Sample Input 0

5
0 4 100000000 5 100000000
100000000 0 1 100000000 6
2 100000000 0 3 100000000
100000000 100000000 1 0 2
1 100000000 100000000 4 0
Sample Output 0

0 4 5 5 7
3 0 1 4 6
2 6 0 3 5
3 7 1 0 2
1 5 5 4 0
*/
void floyd_warshall(vector<vector<int>> &matrix , int n){

    for(int via = 0 ; via<n ; via++){
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){

                // Avoid integer overflow when adding large values
                if (matrix[i][via] != 100000000 && matrix[via][j] != 100000000) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){

            cout << matrix[i][j];
            if (j != n - 1) cout << " ";
        }
    cout << endl;
    }
}


int main(){

    int n;
    cin >> n;
    

    vector<vector<int>> matrix(n,vector<int>(n));

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){

            cin >> matrix[i][j] ;
        }
    }

    // for(int i = 0 ; i<n ; i++){
    //     for(int j = 0 ; j<n ; j++){

    //         cout << matrix[i][j] << " ";
    //     }
    // cout << endl;
    // }

    floyd_warshall(matrix,n);
    return 0;
}