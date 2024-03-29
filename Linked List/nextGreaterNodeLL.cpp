/*
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

 

Example 1:


Input: head = [2,1,5]
Output: [5,5,0]
Example 2:


Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]
*/

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> ans;
    stack<pair<int, int>> s;
    for (int i = 0; head; head = head->next, ++i) {
        while (!s.empty() && head->val > s.top().first) {
            ans[s.top().second] = head->val;
            s.pop();
        }
        
        s.push({head->val, i});
        ans.push_back(0);
    }
    return ans;
}
