#include <bits/stdc++.h>
using namespace std;
//  TC : O(V*E) and SC : O(V) 
/*
Sample Input 0

5 5
1 3 2
4 3 -1
2 4 1
1 2 1
0 1 5
0
Sample Output 0

0 5 6 6 7
*/
int bellmen(vector<vector<int>> &edges , int V , int E , int S){
    
    vector<int> dist(V,1e8);
    dist[S]=0;

    // Relax all edges V-1 times
    for(int i = 0 ; i < V-1 ; i++){
        for(auto &it : edges){

            int u = it[0];
            int v = it[1];
            int w = it[2];
            if( dist[u]!=1e8 && dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative weight cycle
    for(auto &it : edges){

        int u = it[0];
        int v = it[1];
        int w = it[2];
        if( dist[u]!=1e8 && dist[u] + w < dist[v]){
            cout << -1;
            return 0;
        }
    }
    
    // Print final distances
    for (int i = 0; i < V; i++) {
        if (dist[i] == 1e8) dist[i] = 1e8; // unreachable (not required in given test)
        cout << dist[i];
        if (i != V - 1) cout << " ";
    }
    return 0;
}

int main(){
    //  reading inputs
    int V ,E;
    cin >> V >> E;

    vector<vector<int>> edges(E , vector<int>(3));

    for(int i = 0 ; i<E ; i++){

        for(int j = 0 ; j<3 ; j++){

            cin >> edges[i][j];
        }
    }
    int S;
    cin >> S;
    // display inputs 
    /*for(int i = 0 ; i<E ; i++){

        for(int j = 0 ; j<3 ; j++){

            cout << edges[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    bellmen(edges, V , E , S);
    return 0;
}