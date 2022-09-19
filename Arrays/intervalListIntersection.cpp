/*
You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.

The intersection of two closed intervals is a set of real numbers that are either empty or represented as a closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].

 

Example 1:


Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
Example 2:

Input: firstList = [[1,3],[5,9]], secondList = []
Output: []
*/

vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
    int n = f.size(), m = s.size();
    
    int i = 0, j = 0;
    vector<vector<int>> ans;
    
    while (i < n && j < m) {
        if (f[i][0] <= s[j][1] && s[j][0] <= f[i][1])
            ans.push_back({max(f[i][0], s[j][0]), min(f[i][1], s[j][1])});
        
        if (f[i][1] < s[j][1])
            i++;
        else
            j++;
    }
    return ans;
}

// OR

vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
    int n = f.size(), m = s.size();
    
    int i = 0, j = 0;
    vector<vector<int>> ans;
    
    while (i < n && j < m) {
        int l = max(f[i][0], s[j][0]);
        int h = min(f[i][1], s[j][1]);
        if (l <= h)
            ans.push_back({l, h});
        
        if (f[i][1] < s[j][1])
            ++i;
        else
            ++j;
    }
    return ans;
}	
