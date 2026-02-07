#include <bits/stdc++.h>
using namespace std;
/*
You are given an array prices where prices[i] is the price of a given stock on the i-th day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

print the maximum profit you can achieve from this transaction. If you cannot achieve any profit, print 0.

Input Format

The first line contains an integer n , the number of days.
The second line contains n space-separated integers , the stock prices on each day
Constraints

1 ≤ n ≤ 10⁵
0 ≤ prices[i] ≤ 10⁴
Output Format

A single integer, the maximum profit possible. If no profit is possible, output 0.
Sample Input 0

5
9 7 4 3 1
Sample Output 0

0
Sample Input 1

6
3 8 2 5 1 7
Sample Output 1

6
*/

/*

TC : O( n )
SC : O( 1 )
*/
int main(){
    
    int n ; 
    vector<int> profit(n);

     for (int i = 0; i < n; i++) {
        cin >> profit[i]; // read into vector
    }

    int min_price = INT_MAX;
    int max_profit = 0;

    for(auto price : profit){

        min_price  = min(min_price,price);
        max_profit = max(max_profit,price - min_price);
    }

    cout << max_profit;
    return 0;
}