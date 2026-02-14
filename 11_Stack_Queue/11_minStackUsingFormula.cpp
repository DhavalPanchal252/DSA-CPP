#include <bits/stdc++.h>
using namespace std;
// all functions TC  : O(1) , SC : O(n)
struct MinStack{
    stack<long long> st;
    long long mini;

    void push(int v){

        long long val = v;
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else if(val >= mini) 
            st.push(val);
        else{
            st.push(2*val - mini);
            mini = val;
        }
    }

    void pop(){
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini) {
            mini = 2*mini - x;
        }
    }

    int top(){
        if(st.empty()) return -1;

        long long x = st.top();

        if(x >= mini) {
            return int(x);
        }
        else
            return int(mini);
    }

    int minElement(){
        if(st.empty()) return -1;

        return int(mini);
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
