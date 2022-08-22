/*
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.

 

Example 1:

Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]
Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:

Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
Output: [[1,1],[1,1]]
Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:

Input: nums1 = [1,2], nums2 = [3], k = 3
Output: [[1,3],[2,3]]
Explanation: All possible pairs are returned from the sequence: [1,3],[2,3]
*/


vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<vector<int>> ans;
    int n1 = nums1.size(), n2 = nums2.size();
    
    auto comp = [&nums1, &nums2] (pair<int, int> a, pair<int, int> b) {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
    pq.push({0, 0});
    
    while (k-- > 0 && !pq.empty()) {
        int i = pq.top().first, j = pq.top().second;
        pq.pop();
        
        ans.push_back({nums1[i], nums2[j]});
        
        if (i+1 < n1)
            pq.push({i+1, j});
/*Hint : every time you see i,j you just need to push i+1, j into queue. i, j+1 can be pushed into queue later when you see i - 1, j + 1. 
The only exception to this is, when i == 0, there is no i-1, j+1 anymore, so you want to push both i+1, j and i, j+1 when i == 0.*/
        if (i == 0 && j+1 < n2)
            pq.push({i, j+1});
    }
    return ans;
}
