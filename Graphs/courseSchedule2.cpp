/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]
*/

vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> v(n);
        for (auto& a : pre) {
            for (int i = 0; i < 1; i++)
                v[a[1]].push_back(a[0]);
        }
        
        vector<int> in(n, 0);
        for(auto& a : v) {
            for (auto& b : a)
                in[b]++;
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) 
                q.push(i);
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            ans.push_back(f);
            
            for (auto& a : v[f]) {
                in[a]--;
                if (in[a] == 0)
                    q.push(a);
            }
            
        }
            
        if (ans.size() == n)
            return ans;
        return {};
    }
