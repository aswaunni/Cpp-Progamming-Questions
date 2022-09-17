/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]
*/

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *prev = dummy;
    while (head) {
        while (head->next && head->val == head->next->val)
            head = head->next;
        if (prev->next == head)
            prev = head;
        else
            prev->next = head->next;

        head = head->next;
    }
    return dummy->next;
}
