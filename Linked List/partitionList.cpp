/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

 

Example 1:


Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
Example 2:

Input: head = [2,1], x = 2
Output: [1,2]
*/

ListNode* partition(ListNode* head, int x) {
    ListNode h1(-1), h2(-1);
    ListNode* p1 = &h1, *p2 = &h2;
    
    while (head) {
        if (head->val < x) {
            p1->next = head;
            p1 = p1->next;
        } else {
            p2->next = head;
            p2 = p2->next;
        }
        head = head->next;
    }
    p1->next = h2.next;
    p2->next = NULL;
    return h1.next;
}
