/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


*/

ListNode* insertionSortList(ListNode* head) {
    if (!head)
        return head;
    
    ListNode* nHead = new ListNode(-1);
    nHead->next = head;
    
    ListNode* cur = head;
    
    while (cur && cur->next) {
        if (cur->val <= cur->next->val)
            cur = cur->next;
        else {
            ListNode* toInsert = cur->next;
            ListNode* preInsert = nHead;
            while(preInsert->next->val < toInsert->val)
                preInsert = preInsert->next;
            cur->next = toInsert->next;
            toInsert->next = preInsert->next;
            preInsert->next = toInsert;
        }
    }
    return nHead->next;
}
