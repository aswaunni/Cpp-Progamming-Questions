/*
Course Schedule

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

bool cyclic(int i, vector<vector<int>>& m, vector<bool>& vis, vector<bool>& cycleVis) {
    if (cycleVis[i])
        return true;
    
    if (vis[i])
        return false;
    
    vis[i] = true;
    cycleVis[i] = true;
    
    for (auto& edge : m[i]) {
        if (cyclic(edge, m, vis, cycleVis))
            return true;
    }
    
    cycleVis[i] = false;
    return false;
}

bool canFinish(int n, vector<vector<int>>& pre) {
    vector<vector<int>> m(n);
    for (auto& a : pre)
        m[a[1]].push_back(a[0]);
    
    vector<bool> vis(n, false);
    vector<bool> cycleVis(n, false);
    
    for (int i = 0; i < n; i++ ) {
        if (!vis[i] && cyclic(i, m, vis, cycleVis))
            return false;
    }
    return true;
}
