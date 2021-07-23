/*
Skyline Real Estate Developers is planning to demolish a number of old, unoccupied buildings and construct a shopping mall in their place. Your task is to find the largest solid area in which the mall can be constructed.

There are a number of buildings in a certain two-dimensional landscape.

Function Description

Complete the function largestRectangle int the editor below. It should return an integer representing the largest rectangle that can be formed within the bounds of consecutive buildings.

largestRectangle has the following parameter(s):

int h[n]: the building heights
Returns
- long: the area of the largest rectangle that can be formed within the bounds of consecutive buildings

Input Format

The first line contains , the number of buildings.
The second line contains  space-separated integers, each the height of a building.

Sample Input

STDIN       Function
-----       --------
5           h[] size n = 5
1 2 3 4 5   h = [1, 2, 3, 4, 5]
Sample Output

9

*/

long largestRectangle(vector<int> h) {
    h.push_back(0);
    
    stack<int> s;
    long ret = 0;
    int i = 0;
    
    while (i < h.size()) {
        if (s.empty() || h[i] > h[s.top()]) {
            s.push(i);
            i++;
        } else {
            int t = s.top();
            s.pop();
            ret = max(ret, (long)(h[t] * (s.empty() ? i : i - s.top() - 1)));
        }
        
    }
    return ret;
}
