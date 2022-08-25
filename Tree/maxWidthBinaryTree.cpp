/*
Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.

 

Example 1:


Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
Example 2:


Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).
*/

int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    int ans = 0;
    
    while (!q.empty()) {
        int s = q.front().second, e = s;
        int sz = q.size();
        
        while (sz--) {
            TreeNode* f = q.front().first;
            e = q.front().second;
            q.pop();
            
            if (f->left)
                q.push({f->left, 2l*e+1});
            
            if (f->right)
                q.push({f->right, 2l*e+2});
        }
        
        ans = max(ans, e-s+1);
    }
    return ans;
}
