#include <bits/stdc++.h>
using namespace std;

/*
Binary Subarrays With Sum

Given a binary array nums and an integer goal,
return the number of non-empty subarrays with sum = goal.
*/


// TC : O(N^2) , SC : O(1)

int helperBruteForce(vector<int> &arr, int n , int goal){

    int cnt = 0;

    for(int i = 0 ; i < n ; i++){

        int sum = 0;

        for(int j = i ; j < n ; j++){

            sum += arr[j];

            if(sum <= goal){
                cnt++;
            }
            else{
                break;
            }
        }
    }

    return cnt;
}


int bruteForce(vector<int> &arr, int n , int goal){

    return helperBruteForce(arr, n, goal) - helperBruteForce(arr, n, goal - 1);
}



// TC : O(N) , SC : O(1)

int helper(vector<int> &nums, int goal , int n){

    if(goal < 0) return 0;

    int l = 0;
    int r = 0;

    int cnt = 0;
    int sum = 0;

    while(r < n){

        sum += nums[r];

        while(sum > goal){

            sum -= nums[l];

            l++;
        }

        cnt += (r - l + 1);

        r++;
    }

    return cnt;
}


int optimal(vector<int>& nums, int n , int goal){

    return helper(nums , goal , n) - helper(nums , goal - 1 , n);
}


int main(){
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(auto &i : arr) cin >> i;

    int goal;
    cin >> goal;

    // cout << bruteForce(arr, n, goal);
    cout << optimal(arr, n, goal);

    return 0;
}