/*
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
Example 2:

Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
Example 3:

Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
*/

int eraseOverlapIntervals(vector<vector<int>>& it) {
    sort(it.begin(), it.end());
    int ans = 0;
    int e = it[0][1];
    for (int i = 1; i < it.size(); ++i) {
        if (e <= it[i][0])
            e = it[i][1];
        else {
            ++ans;
            e = min(e, it[i][1]);
        }
    }
    return ans;
}

// OR

int eraseOverlapIntervals(vector<vector<int>>& it) {
    sort(it.begin(), it.end(), [] (vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });
    
    int ans = 0;
    int e = it[0][1];
    for (int i = 1; i < it.size(); ++i) {
        if (e <= it[i][0])
            e = it[i][1];
        else
            ++ans;
    }
    return ans;
}
