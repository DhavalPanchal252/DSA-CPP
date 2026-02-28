#include <bits/stdc++.h>
using namespace std;

vector<int> findNse(vector<int> &hist){
    stack<int> st;
    int n = hist.size();
    vector<int> nse(n);

    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && hist[i] <= hist[st.top()]){
            st.pop();
        }

        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return nse;
}

vector<int> findPse(vector<int> &hist){
    stack<int> st;
    int n = hist.size();
    vector<int> pse(n);

    for(int i = 0; i < n; i++){
        while(!st.empty() && hist[i] <= hist[st.top()]){
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

int findMaxHistogram(vector<int> &hist){
    vector<int> nse = findNse(hist);
    vector<int> pse = findPse(hist);

    long long maxi = 0;

    for(int i = 0; i < hist.size(); i++){
        long long width = nse[i] - pse[i] - 1;
        long long area = 1LL * hist[i] * width;

        maxi = max(maxi, area);
    }

    return maxi;
}

int maximalRectangle(vector<vector<char>> &matrix){

    if(matrix.empty()) return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<int> height(cols, 0);
    int maxi = 0;

    for(int i = 0; i < rows; i++){

        for(int j = 0; j < cols; j++){
            if(matrix[i][j] == '1')
                height[j]++;
            else
                height[j] = 0;
        }

        maxi = max(maxi, findMaxHistogram(height));
    }

    return maxi;
}

int main(){

    int r, c;
    cin >> r >> c;

    vector<vector<char>> matrix(r, vector<char>(c));

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> matrix[i][j];
        }
    }

    cout << maximalRectangle(matrix);

    return 0;
}