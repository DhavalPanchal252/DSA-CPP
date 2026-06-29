#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Disjoint Set Union (DSU)

              Union by Rank
          + Path Compression

--------------------------------------------------

Problem

Maintain a collection of disjoint sets.

Support two operations efficiently.

1. Find

Determine which set a node belongs to.

2. Union

Merge two different sets.

--------------------------------------------------

Applications

✓ Kruskal's Algorithm

✓ Number of Provinces

✓ Number of Islands

✓ Dynamic Connectivity

✓ Cycle Detection

--------------------------------------------------

Data Structures

parent[i]

Stores the parent of node i.

Initially,

Every node is its own parent.

parent[i] = i

-----------------------------

rank[i]

Stores the approximate height
of the tree.

Used to keep the tree shallow.

--------------------------------------------------

Path Compression

Whenever Find() is called,

directly connect every visited node

to its ultimate parent.

Before

7 → 6 → 4 → 2

After Find(7)

7 → 2
6 → 2
4 → 2

Tree becomes almost flat.

--------------------------------------------------

Union by Rank

Attach the smaller height tree

under

the larger height tree.

If both heights are equal,

attach one under another

and increase the rank.

--------------------------------------------------

Time Complexity

Find

≈ O(1)

Union

≈ O(1)

More precisely

O(α(N))

where α(N)

is the Inverse Ackermann Function.

It grows so slowly that

α(N) ≤ 5

for all practical inputs.

--------------------------------------------------

Space Complexity

O(N)

==================================================
*/

class DisjointSet
{
    vector<int> parent;
    vector<int> rank;

public:

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Find Ultimate Parent
    // with Path Compression

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] =
            findUltimateParent(parent[node]);
    }

    // Union by Rank

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    /*
            Initially

            1   2   3   4   5   6   7

            Each node is its own parent.

            Perform

            Union(1,2)
            Union(2,3)
            Union(4,5)
            Union(6,7)

            Sets

            {1,2,3}

            {4,5}

            {6,7}

            Check

            3 and 7 ?

            Different Sets

            ---------------------

            Union(3,7)

            Sets become

            {1,2,3,6,7}

            {4,5}

            Now

            3 and 7

            Same Set
    */

    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);

    ds.unionByRank(4, 5);

    ds.unionByRank(6, 7);

    if (ds.findUltimateParent(3) ==
        ds.findUltimateParent(7))
    {
        cout << "Same Parent\n";
    }
    else
    {
        cout << "Not Same Parent\n";
    }

    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3) ==
        ds.findUltimateParent(7))
    {
        cout << "Same Parent\n";
    }
    else
    {
        cout << "Not Same Parent\n";
    }

    return 0;
}