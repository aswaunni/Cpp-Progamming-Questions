/*
Given the root of a binary tree, return all duplicate subtrees.

For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with the same node values.

 

Example 1:


Input: root = [1,2,3,4,null,2,4,null,null,4]
Output: [[2,4],[4]]
Example 2:


Input: root = [2,1,1]
Output: [[1]]
*/

string postOrder(TreeNode* root, unordered_map<string, vector<TreeNode*>>& m) {
    if (!root)
        return "#";
    
    string s = to_string(root->val) + "," + postOrder(root->left, m) + "," + postOrder(root->right, m);
    m[s].push_back(root);
    return s;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    unordered_map<string, vector<TreeNode*>> m;
    postOrder(root, m);
    
    vector<TreeNode*> ans;
    for (auto& [a, b] : m) {
        if (b.size() > 1)
            ans.push_back(b[0]);
    }
    return ans;
}
