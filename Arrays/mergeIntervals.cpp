/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

vector<vector<int>> merge(vector<vector<int>>& it) {
    vector<vector<int>> ans;
    sort(it.begin(), it.end());
    int start = it[0][0], end = it[0][1];
    int n = it.size();
    
    for (int i = 1; i < n; i++) {
        if (end < it[i][0]) {
            ans.push_back({start, end});
            start = it[i][0];
            end = it[i][1];
        } else {
            start = min(start, it[i][0]);
            end = max(end, it[i][1]);
        }
    }
    ans.push_back({start, end});
    return ans;
}

// OR 
	
vector<vector<int>> merge(vector<vector<int>>& it) {
    vector<vector<int>> ans;
    sort(it.begin(), it.end());
    
    for (auto& a : it) {
        if (ans.empty() || ans.back()[1] < a[0])
            ans.push_back({a[0], a[1]});
        else
            ans.back()[1] = max(ans.back()[1], a[1]);
    }
    return ans;
}
