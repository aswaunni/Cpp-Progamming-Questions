/*
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
*/

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root)
        return ans;
    
    queue<TreeNode*> q;
    bool flag = true;
    
    q.push(root);
    
    while (!q.empty()) {
        int sz = q.size();
        vector<int> v(sz);
        for (int i = 0; i < sz; ++i) {
            TreeNode* f = q.front();
            q.pop();
            
            int idx = (flag ? i : sz - i - 1);
            v[idx] = f->val;
            
            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }
        flag = !flag;
        ans.push_back(v);
    }
    return ans;
}
