vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int sz = q.size();
        ans.push_back(q.front()->val);
        while (sz--) {
            TreeNode* f = q.front();
            q.pop();
            
            if (f->right) q.push(f->right);
            if (f->left) q.push(f->left);
        }
    }
    return ans;
}

// OR (Recursion)

void check(TreeNode* r, vector<int>& ans, int level) {
    if (r == NULL)
        return;
    
    if (level == ans.size())
        ans.push_back(r->val);
    
    check(r->right, ans, level+1);
    check(r->left, ans, level+1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    check(root, ans, 0);
    return ans;
}
