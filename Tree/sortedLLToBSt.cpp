/*
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

 

Example 1:


Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: One possible answer is [0,-3,9,-10,null,5], which represents the shown height balanced BST.
Example 2:

Input: head = []
Output: []
 
 */

TreeNode* helper(ListNode* head, ListNode* tail) {
    ListNode* slow = head, *fast = head;
    
    if (head == tail)
        return NULL;
    
    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    TreeNode* node = new TreeNode(slow->val);
    node->left = helper(head, slow);
    node->right = helper(slow->next, tail);
    return node;
}

TreeNode* sortedListToBST(ListNode* head) {
    if (!head)
        return NULL;
    return helper(head, NULL);
}
