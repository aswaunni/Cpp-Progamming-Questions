/*
Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.

The length of the path between two nodes is represented by the number of edges between them.

 

Example 1:


Input: root = [5,4,5,1,1,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 5).
Example 2:


Input: root = [1,4,5,4,4,null,5]
Output: 2
Explanation: The shown image shows that the longest path of the same value (i.e. 4).
*/

int dfs(TreeNode* root, int& ans, int val) {
    if (!root)
        return 0;
    int left = dfs(root->left, ans, root->val);
    int right = dfs(root->right, ans, root->val);
    
    ans = max(ans, left + right);
    
    return (root->val == val ? 1 + max(left, right) : 0);
}

int longestUnivaluePath(TreeNode* root) {
    if (!root)
        return 0;
    int ans = 0;
    dfs(root, ans, root->val);
    return ans;
}
