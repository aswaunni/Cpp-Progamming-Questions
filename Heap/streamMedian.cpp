/*
Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of the stream formed by each insertion of X to the new stream.

Example 1:

Input:
N = 4
X[] = 5,15,1,3
Output:
5
10
5
4
Explanation:Flow in stream : 5, 15, 1, 3 
5 goes to stream --> median 5 (5) 
15 goes to stream --> median 10 (5,15) 
1 goes to stream --> median 5 (5,15,1) 
3 goes to stream --> median 4 (5,15,1 3) 
 

Example 2:

Input:
N = 3
X[] = 5,10,15
Output:
5
7.5
10
Explanation:Flow in stream : 5, 10, 15
5 goes to stream --> median 5 (5) 
10 goes to stream --> median 7.5 (5,10) 
15 goes to stream --> median 10 (5,10,15) 
*/

class Solution
{
    public:
    priority_queue<int> s; // smaller half elements
    priority_queue<int, vector<int>, greater<int>> g; // greater half elements
    
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if (s.size() > g.size()) {
            if (x > s.top())
                g.push(x);
            else {
                s.push(x);
                g.push(s.top());
                s.pop();
            }
        } else {
            if (s.empty() || x <= s.top())
                s.push(x);
            else {
                g.push(x);
                s.push(g.top());
                g.pop();
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
    }
    
    //Function to return Median.
    double getMedian()
    {
        double ans;
        if (s.size() == g.size()) {
            ans = (s.top() + g.top())/(double)2;
        } else 
            ans = s.top();
        return ans;
    }
};
