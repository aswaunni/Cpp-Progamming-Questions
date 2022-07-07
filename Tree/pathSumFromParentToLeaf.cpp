/*
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
Example 1:

Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
*/

int pathSum(TreeNode* root, int sum) {
    if(!root) return 0;
    return dfs(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
}

int dfs(TreeNode* r, long long sum){
    if(!r) return 0;
    return (r->val == sum) + dfs(r->left, sum - r->val) + dfs(r->right, sum - r->val);
}

// OR

unordered_map<long long, int> m;
int ans =  0;
    
void dfs(TreeNode* r, long long cur, int sum) {
    if (r == NULL)
        return;
    
    cur += r->val;
    ans += m[cur - sum];
    m[cur]++;
    
    dfs(r->left, cur, sum);
    dfs(r->right, cur, sum);
    
    m[cur]--;
}

int pathSum(TreeNode* root, int sum) {
    if(!root) 
        return 0;
    m[0] = 1;
    dfs(root, 0, sum);
    return ans;        
}
