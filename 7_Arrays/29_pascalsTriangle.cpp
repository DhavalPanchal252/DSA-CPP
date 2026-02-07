#include <bits/stdc++.h>
using namespace std;

// Approach - 1
void approach1(int rowNum){ // TC : O(n^2) , SC : O(n^2)
    
    vector<vector<int>> triangle ;

    for(int i=0 ; i<rowNum ; i++){

        vector<int> row(i+1,1);

        for(int j=1 ; j<i ; j++){
            row[j] = triangle[i-1][j-1] +triangle[i-1][j];
        }

        triangle.push_back(row);
    }

    for(auto &rows : triangle){
        for(auto &i : rows){
            cout << i << " ";
        }
        cout << endl;
    }
}

// Approach - 2
// In Pascal’s Triangle, the element at row R and column C corresponds to the binomial coefficient (r-1)C(c-1).

void approach2(int rowNum) { // TC : O(n) , SC : O(n)

    vector<long long> row;

    long long val = 1;
    row.push_back(val);

    for(int i = 1; i < rowNum; i++) {
        val = val * (rowNum - i ) / i;
        row.push_back(val);
    }
    
    for (auto &i : row) {
        cout << i << " ";
    }
}

// Using approch 2 print all rows
void approach1_other(int rowNum){ // TC : O(n^2) , SC : O(n^2)
    
    vector<vector<long long>> triangle;

    for(int i = 1 ; i <= rowNum ; i++){

        vector<long long> row;

        long long val = 1;
        row.push_back(val);

        for(int j = 1; j < i; j++) {
            val = val * (i - j) / j;
            row.push_back(val);
        }

        triangle.push_back(row);
    }

    for(auto &rows : triangle){
        for(auto &i : rows){
            cout << i << " ";
        }
        cout << endl;
    }
}

// Approach - 3
//  the element at the coordinates (R,C) where R is the row number and C is the Column number

void approach3(int row , int col){ // TC : O(n) , SC : O(1)
    int r = row -1 ; 
    int c = col -1 ;
    
    long long val = 1 ;

    for(int i = 1; i <= c; i++) {
        val = val * (r - i + 1) / i;
    }
    cout << val ;
}

int main(){
    
    int n;
    cin >> n;

    // approach1(n);
    approach1_other(n);
    // approach2(n);
    // approach3(5,3);
    return 0;
}