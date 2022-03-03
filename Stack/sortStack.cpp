/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
*/

void sortedInsert(stack<int>& s, int x)
{
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }
    
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);
    s.push(temp);
}

void sort()
{
   if (!s.empty()) {
        int num=s.top();
        s.pop();
        sort();
        sortedInsert(s,num);
   }
}

// OR

stack<int> sortStack(stack<int> &input)
{
    stack<int> tmpStack;

    while (!input.empty())
    {
        int tmp = input.top();
        input.pop();

        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }

        tmpStack.push(tmp);
    }

    return tmpStack;
}
