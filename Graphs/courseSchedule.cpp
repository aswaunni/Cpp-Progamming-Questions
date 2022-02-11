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

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int n = numCourses;
    
    vector<vector<int>> dependency(n);
    vector<bool> visited(n, false), curClassVisited(n, false);
    
    for (auto& p : prerequisites)
        dependency[p[0]].push_back(p[1]);
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && isCyclic(i, dependency, visited, curClassVisited))
            return false; 
    }
    return true;
}

bool isCyclic(int i, vector<vector<int>>& dependency, vector<bool>& visited, vector<bool>& curClassVisited) {
    visited[i] = true;
    curClassVisited[i] = true;
    
    for (auto& d : dependency[i]) {
        if ((!visited[d] && isCyclic(d, dependency, visited, curClassVisited)) ||  curClassVisited[d])
            return true;
    }
    curClassVisited[i] = false; //backtracking
    return false;
}
