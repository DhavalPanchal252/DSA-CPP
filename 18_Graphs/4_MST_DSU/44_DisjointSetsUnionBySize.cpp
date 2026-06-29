#include <bits/stdc++.h>
using namespace std;

/*
==================================================
        Disjoint Set Union (DSU)

              Union by Size
          + Path Compression

--------------------------------------------------

Problem

Maintain a collection of disjoint sets.

Support two operations efficiently.

1. Find

Determine the set to which
a node belongs.

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

size[i]

Stores the number of nodes
present in the set.

Initially,

Every set contains

1 node.

--------------------------------------------------

Path Compression

Whenever Find() is called,

every visited node

is directly connected

to its ultimate parent.

Example

Before

7 → 6 → 4 → 2

After Find(7)

7 → 2
6 → 2
4 → 2

Tree becomes almost flat.

--------------------------------------------------

Union by Size

Merge the smaller set

into

the larger set.

Update the size

of the larger set.

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

--------------------------------------------------

Space Complexity

O(N)

==================================================
*/

class DisjointSet
{
    vector<int> parent;
    vector<int> size;

public:

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);

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

    // Union by Size

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        // Attach smaller set
        // below larger set

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    /*
            Initially

            1   2   3   4   5   6   7

            Each node forms
            its own set.

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

            3 and 7

            Different Sets

            ----------------------

            Union(3,7)

            Sets become

            {1,2,3,6,7}

            {4,5}

            Now

            3 and 7

            Same Set
    */

    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);

    ds.unionBySize(4, 5);

    ds.unionBySize(6, 7);

    if (ds.findUltimateParent(3) ==
        ds.findUltimateParent(7))
    {
        cout << "Same Parent\n";
    }
    else
    {
        cout << "Not Same Parent\n";
    }

    ds.unionBySize(3, 7);

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