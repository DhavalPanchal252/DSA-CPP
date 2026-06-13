#include <bits/stdc++.h>
using namespace std;

/*
Candy

There are n children standing in a line.

Each child has a rating given in the array ratings.

Rules:
1. Every child must have at least one candy.
2. Children with a higher rating than their
   immediate neighbor must get more candies.

Return the minimum number of candies needed.
*/


/*
Approach:

Left Pass:
- If current rating is greater than the left neighbor,
  give one more candy than the left neighbor.

Right Pass:
- If current rating is greater than the right neighbor,
  give one more candy than the right neighbor.

For each child:
- Take max(left[i], right[i]) to satisfy both sides.

TC : O(N)
SC : O(N)
*/
int candy(vector<int>& ratings) {

    int n = ratings.size();

    vector<int> left(n);
    vector<int> right(n);

    left[0] = 1;
    right[n - 1] = 1;

    // Left to Right
    for(int i = 1; i < n; i++) {

        if(ratings[i] > ratings[i - 1]) {
            left[i] = left[i - 1] + 1;
        }
        else {
            left[i] = 1;
        }
    }

    // Right to Left
    for(int i = n - 2; i >= 0; i--) {

        if(ratings[i] > ratings[i + 1]) {
            right[i] = right[i + 1] + 1;
        }
        else {
            right[i] = 1;
        }
    }

    int totalCandies = 0;

    for(int i = 0; i < n; i++) {

        totalCandies += max(left[i], right[i]);
    }

    return totalCandies;
}

int main() {

    int n;
    cin >> n;

    vector<int> ratings(n);

    for(auto &i : ratings)
        cin >> i;

    cout << candy(ratings);

    return 0;
}