#include <bits/stdc++.h>
using namespace std;

struct MyStack{
    int n;
    int top;
    vector<int> arr;

    MyStack(int n1){
        n = n1;
        arr = vector<int>(n,-1);
        top = -1;
    }

    void push(int x){

        if(isFull()){
            cout << "Over Flow" << endl; 
            return;   
        }
        arr[++top] = x;
    }

    int pop(){
        if(isEmpty()) return -1;
        
        return arr[top--];
    }

    int peek(){
        if(isEmpty()) {
            cout << "Under Flow" << endl;
            return -1;
        }
        return arr[top];
    }

    int size(){
        return top + 1;
    }
    bool isEmpty(){
        return top == -1;
    }
    bool isFull(){
        return top == n-1;
    }
};

int main(){
    
    MyStack st(6);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    cout << "pop : " << st.pop() << endl;
    st.push(7);
    cout << "peek : " << st.peek() << endl;
    cout << "Is Empty : " << st.isEmpty() << endl;
    cout << "Is Full : " << st.isFull() << endl;
    cout << "size  :    " << st.size() << endl;

    for(auto &i : st.arr) cout << i << " ";

    return 0;
}