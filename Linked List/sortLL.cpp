ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
        return head;
    
    ListNode* slow = head, *fast = head;
    
    ListNode* t = NULL;
    while (fast && fast->next) {
        t = slow; 
        slow = slow->next;
        fast = fast->next->next;
    }
    t->next = NULL; // end of first half
    
    ListNode* l1 = sortList(head);
    ListNode* l2 = sortList(slow);
    
    return mergeList(l1, l2);
}

ListNode* mergeList(ListNode* h1, ListNode* h2) {
    ListNode* head = new ListNode(-1);
    ListNode* cur = head;
    while (h1 || h2) {
        int v1 = (h1 ? h1->val : INT_MAX);
        int v2 = (h2 ? h2->val : INT_MAX);
        if (v1 > v2) {
            cur->next = h2;
            h2 = h2->next;
        } else {
            cur->next = h1;
            h1 = h1->next;
        }
        cur = cur->next;
    }
    return head->next;
}
