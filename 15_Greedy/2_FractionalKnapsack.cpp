#include <bits/stdc++.h>
using namespace std;

/*
Fractional Knapsack

Given n items where:
price[i] = value of item
weight[i] = weight of item

You may take fractions of an item.

Return the maximum value that can be put
into a knapsack of capacity W.
*/

static bool comparator(const pair<int,int> &a, const pair<int,int> &b) {

    return ((double)a.first / a.second) >
           ((double)b.first / b.second);
}

/*
TC : O(N log N)
     - O(N) for creating the vector of pairs
     - O(N log N) for sorting based on value/weight ratio
     - O(N) for traversing the sorted items

SC : O(N)
     - Extra vector of pairs is used
*/
double knapsack(int n, vector<int> price, vector<int> weight, int capacity) {

    double ans = 0;

    vector<pair<int,int>> vec;

    for(int i = 0; i < n; i++) {
        vec.push_back({price[i], weight[i]});
    }

    sort(vec.begin(), vec.end(), comparator);

    for(auto &item : vec) {

        if(item.second <= capacity) {

            ans += item.first;
            capacity -= item.second;
        }
        else {

            ans += ((double)capacity / item.second) * item.first;
            break;
        }
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> price(n);
    for(auto &i : price) cin >> i;

    vector<int> weight(n);
    for(auto &i : weight) cin >> i;

    int capacity;
    cin >> capacity;

    cout << knapsack(n, price, weight, capacity);

    return 0;
}