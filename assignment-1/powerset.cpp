#include <bits/stdc++.h>
using namespace std;
/*
Given a list of distinct integers nums, print all possible subsets (the power set). The solution must not contain duplicate subsets. You may print the subsets in any order.

Input Format

The first line contains a single integer n, the number of elements in the array.
The second line contains n space-separated integers, the elements of the array.
Constraints

1 ≤ nums.length ≤ 10
-10 ≤ nums[i] ≤ 10
Output Format

Output should be a list of lists.
Each subset should be enclosed in square brackets [], and the entire output must be enclosed in square brackets too.
Sample Input 0

1
0
Sample Output 0

[[], [0]]
Sample Input 1

2
1 2
Sample Output 1

[[], [1], [2], [1, 2]]
*/

/*

TC : O( n*2^n )
SC : O( n*2^n )
*/
int main(){
    int n;
    cin >> n;

    vector<int> nums(n);
    for(auto &i : nums){
        cin >> i;
    }

    vector<vector<int>> ans;

    int size = 1 << n;  // means 2 power n

    for(int i =  0 ; i< size ; i++){ // 2^n

        vector<int> subset;

        for(int j = 0 ; j < n ; j++){ // n

            if( i & 1<<j){
                subset.push_back(nums[j]);
            }
        }

        ans.push_back(subset);
    }
    
    cout << "[" ;

    for(int i = 0 ; i < (int)ans.size() ; i++){

        cout << "[" ;

        for(int j = 0 ; j < (int)ans[i].size() ; j++){

            cout << ans[i][j];

            if( j != (int)ans[i].size()-1) cout << ", ";
        
        }
        cout << "]"; 
        if( i != (int)ans.size()-1) cout << ", ";

    }
    cout << "]";

    return 0;
}
