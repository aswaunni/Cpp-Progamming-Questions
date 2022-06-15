/*
class StackQueue{
private:   
// These are STL stacks ( http://goo.gl/LxlRZQ )
stack<int> s1;
stack<int> s2;
public:
void push(int);
int pop();
}; */

//Function to push an element in queue by using 2 stacks.
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top; 
         
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        int pop() {
            if (stack_oldest_on_top.empty()) {
                while (!stack_newest_on_top.empty()) {
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
            }
            return stack_oldest_on_top.pop();
        }
};

//OR

class MyQueue {
  
    public:
        stack<int> s1; 
               
        void push(int x) {
            s1.push(x);
        }

        int pop() {
            if (s1.empty())
                return -1;
            int x = s1.top();
            s1.pop();
            if (s1.empty())
                return x;
            int y = pop();
            s1.push(x);
            return y;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2)
            cout << q1.pop() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}

