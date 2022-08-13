/*
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

 

Example 1:


Input: root = [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: We have various ancestor-node differences, some of which are given below :
Example 2:


Input: root = [1,null,2,null,0,3]
Output: 3
*/
 int maxAncestorDiff(TreeNode* root, int mn = 100001, int mx = 0) {
    if (root == NULL)
        return mx - mn;
    
    mn = min(root->val, mn);
    mx = max(root->val, mx);
    
    return max(maxAncestorDiff(root->left, mn, mx), maxAncestorDiff(root->right, mn, mx));
}

 OR


int ans = 0;
pair<int, int> dfs(TreeNode* root) {
    if (root == NULL)
        return {100001, 0};
    
    pair<int, int> l = dfs(root->left);
    pair<int, int> r = dfs(root->right);
    
    int mn = min({root->val, l.first, r.first});
    int mx = max({root->val, l.second, r.second});
    
    ans = max(ans, max(root->val - mn, mx - root->val ));
    
    return {mn, mx};
}

int maxAncestorDiff(TreeNode* root) {
    auto p = dfs(root);
    return ans;
}
