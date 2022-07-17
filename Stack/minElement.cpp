/*
Design a data-structure SpecialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element from the SpecialStack. Your task is to complete all the functions, using stack data-Structure.


Example 1:

Input:
Stack: 18 19 29 15 16
Output: 15
Explanation:
The minimum element of the stack is 15.
*/

int demoVal = 10001;
int mn = -1;

void push(stack<int>& s, int a) {

	if (s.empty() || a < mn)
	    mn = a;
	    
	s.push(demoVal*a + mn);
}

int pop(stack<int>& s){
	if (s.empty())
	    return -1;
	int x = s.top();
	s.pop();
	if (s.empty()) 
	    mn = -1;
	else
	    mn = x%demoVal;
	return x/demoVal;
}

int getMin(stack<int>& s){
	return mn;
}

//OR

stack<int> minS;

void push(stack<int>& s, int a) {

	if (s.empty() || a < minS.top())
	    minS.push(a);
	else {
	    int x = minS.top();
	    minS.push(x);
	}
	s.push(a);
}

int pop(stack<int>& s){
	if (s.empty())
	    return -1;
	int x = s.top();
	s.pop();
	minS.pop();
	return x;
}

int getMin(stack<int>& s){
	return minS.top();
}

// OR

void push(int val) {
    if (val <= mn) {
        s.push(mn);
        mn = val;
    }
    s.push(val);
}

void pop() {
    if (s.top() == mn) {
        s.pop();
        mn = s.top();
    }
    s.pop();
}

int top() {
    return s.top();
}

int getMin() {
    return mn;
}
