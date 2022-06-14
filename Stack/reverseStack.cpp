#include <bits/stdc++.h>

using namespace std;

void insertAtBottom(stack<int>& st, int x) {
    if(!st.empty()) {
        int y = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(y);
    } else
        st.push(x);
}

void reverseStack(stack<int>& st) {
    if (!st.empty()) {
        int x = st.top();
        st.pop();
        reverseStack(st);
        insertAtBottom(st, x);
    }
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    printStack(s);

    reverseStack(s);
    printStack(s);  
    return 0;
}
