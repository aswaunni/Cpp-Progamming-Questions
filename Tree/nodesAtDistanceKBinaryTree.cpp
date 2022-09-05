class Solution {
public:
    vector<int> ans;
    
    void dfs(TreeNode* root, int k) {
        if (!root || k < 0)
            return;
        
        if (k == 0) {
            ans.push_back(root->val);
            return;
        }
        
        dfs(root->left, k-1);
        dfs(root->right, k-1);
    }
    
    int find(TreeNode* root, TreeNode* t, int k) {
        if (root == NULL)
            return -1;
        
        if (root == t) {
            dfs(root, k);
            return 0;
        }
        
        int left = find(root->left, t, k);
        if (left >= 0) {
            if (left+1 == k)
                ans.push_back(root->val);
            else
                dfs(root->right, k-2-left);
            return left+1;
        }
        
        int right = find(root->right, t, k);
        if (right >= 0) {
            if (right+1 == k)
                ans.push_back(root->val);
            else
                dfs(root->left, k-2-right);
            return right + 1;
        }
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find(root, target, k);
        
        return ans;
    }
};

// OR

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> m;
    unordered_set<int> vis;
    vector<int> ans;
    
    void find(TreeNode* root) {
        if (root == NULL)
            return;
        
        if (root->left){
            m[root->left] = root;
            find(root->left);
        }
        
        if (root->right) {
            m[root->right] = root;
            find(root->right);
        }
    }
    
    void dfs(TreeNode* target, int k) {
        if (!target)
            return;
        
        if (vis.count(target->val))
            return;
        
        vis.insert(target->val);
        
        if (k == 0) {
            ans.push_back(target->val);
            return;
        }
        
        dfs(target->left, k-1);
        dfs(target->right, k-1);
        
        if (m[target]) 
            dfs(m[target], k-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find(root);
        dfs(target, k);
        
        return ans;
    }
};
