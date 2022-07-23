/*
You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

Return a list of integers representing the size of these parts.

 

Example 1:

Input: s = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.
Example 2:

Input: s = "eccbbbbdec"
Output: [10]
*/

vector<int> partitionLabels(string s) {
    int n = s.length();
    vector<int> lastOcc(26, -1);
    
    for (int i = 0; i < n; i++)
        lastOcc[s[i] - 'a'] = i;
    
    vector<int> ans;
    int start = -1, end = 0;
    
    for (int i = 0; i < n; i++) {
        end = max(end, lastOcc[s[i] - 'a']);
        
        if (i == end) {
            ans.push_back(end-start);
            start = end;
        }
    }
    return ans;
}
