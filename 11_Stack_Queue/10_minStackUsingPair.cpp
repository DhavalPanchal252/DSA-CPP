#include <bits/stdc++.h>
using namespace std;
// all functions TC : O(1) but we require extra space... total O(2n)
struct MinStack{
    stack<pair<int,int>> st;

    void push(int val){
        if(st.empty()){
            st.push({val, val});
        }
        else{
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }

    void pop(){
        if(st.empty()) return;
        st.pop();
    }

    int top(){
        if(st.empty()) return -1;
        return st.top().first;
    }

    int minElement(){
        if(st.empty()) return -1;
        return st.top().second;
    }

    bool isEmpty(){
        return st.empty();
    }
};

int main(){
    
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << "Top: " << ms.top() << endl;
    cout << "Min: " << ms.minElement() << endl;

    ms.pop();

    cout << "After Pop -> Min: " << ms.minElement() << endl;

    return 0;
}
