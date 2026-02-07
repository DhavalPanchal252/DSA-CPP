#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> st; // always sorted and unique

    st.insert(1);   // {1}
    st.emplace(2);  // {1, 2}
    st.insert(2);   // still {1, 2} – duplicates not allowed
    st.insert(4);   // {1, 2, 4}
    st.insert(3);   // {1, 2, 3, 4}
   
    auto it = st.find(3); // points to address at 3 ele

    auto it = st.find(6); // points to address after 4 ele ,bcz if ele not present then it returns st.end()
    
    int cnt = st.count(2); // if element exist then always returns 1 ow 0

    st.erase(2); // 1 2 4  ,  takes logarithm timne

    auto it = st.find(4);
    st.erase(it); // takes constant time
    // if {1, 2, 3, 4}
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1,it2);// after erase {1, 4}
    //rest of functions like insert,size,swap,begin,end,rbegin,rend are same as the vector

    return 0;
}