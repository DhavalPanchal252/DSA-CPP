#include <bits/stdc++.h>
using namespace std;

/*
==================================================
      Minimum Multiplications to Reach End

                 BFS on Graph

--------------------------------------------------

Problem

Given

start
end
array of multipliers

In one operation,

current = (current * arr[i]) % 1000

Find the minimum number of operations
required to reach

start -------------> end

If impossible,

return -1.

--------------------------------------------------

Graph Representation

Every number

0 to 999

is considered as a node.

From every node,

we can move to

(current * arr[i]) % 1000

for every multiplier in arr[].

--------------------------------------------------

Why BFS?

Each multiplication costs

1 operation.

All edges have equal weight.

For graphs having equal edge weights,

BFS always finds the shortest path.

--------------------------------------------------

State stored in Queue

{steps, currentNumber}

Example

{3, 95}

means

Current number = 95

Reached in 3 multiplications.

--------------------------------------------------

Transition

Next Node

(current * multiplier) % 1000

If

steps + 1 < dist[next]

Update distance

Push into queue.

--------------------------------------------------

Stopping Condition

If current number becomes end,

return current number of steps.

--------------------------------------------------

Time Complexity

O(1000 × N)

N = size of arr

There are only 1000 possible states
(0 to 999).

--------------------------------------------------

Space Complexity

O(1000)

==================================================
*/

int minSteps(vector<int>& arr, int start, int end)
{
    if (start == end)
        return 0;

    const int MOD = 1000;

    vector<int> dist(MOD, 1e9);

    dist[start] = 0;

    // {steps, currentValue}

    queue<pair<int,int>> q;

    q.push({0, start});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int steps = it.first;
        int cur = it.second;

        if (cur == end)
            return steps;

        // Ignore outdated state

        if (steps > dist[cur])
            continue;

        for (int x : arr)
        {
            int next = (cur * x) % MOD;

            if (dist[next] > steps + 1)
            {
                dist[next] = steps + 1;

                q.push({steps + 1, next});
            }
        }
    }

    return -1;
}

int main()
{
    /*
            Multipliers

            {3, 4, 65}

            Start = 7
            End = 175

            Path

            7
             |
            ×3
             |
            21
             |
            ×3
             |
            63
             |
            ×65
             |
            95
             |
            ×65
             |
            175

            Minimum Steps = 4
    */

    vector<int> arr = {3, 4, 65};

    int start = 7;
    int end = 175;

    cout << "Minimum Steps = "
         << minSteps(arr, start, end)
         << endl;

    return 0;
}