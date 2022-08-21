/*
Given the root of a binary tree, each node in the tree has a distinct value.

After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

Return the roots of the trees in the remaining forest. You may return the result in any order.

 

Example 1:


Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]
Output: [[1,2,null,4],[6],[7]]
Example 2:

Input: root = [1,2,4,null,3], to_delete = [3]
Output: [[1,2,4]]
*/

class Solution {
public:
    vector<TreeNode*> ans;
    
    TreeNode* dfs(TreeNode* root, unordered_set<int>& st) {
        if (root == NULL)
            return NULL;
        
        root->left = dfs(root->left, st);
        root->right = dfs(root->right, st);
        
        if (st.count(root->val)) {
            st.erase(root->val);
            if (root->left)
                ans.push_back(root->left);
            if (root->right)
                ans.push_back(root->right);
            return NULL;
        }
        
        return root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        
        root = dfs(root, st);
        if (root)
            ans.push_back(root);
        return ans;
    }
};
