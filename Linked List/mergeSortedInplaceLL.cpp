/*
Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) and return head of the merged list.
 

 Example 1:

 Input:
 N = 4, M = 3 
 valueN[] = {5,10,15,40}
 valueM[] = {2,3,20}
 Output: 2 3 5 10 15 20 40
 Explanation: After merging the two linked
 lists, we have merged list as 2, 3, 5,
 10, 15, 20, 40.
*/

node* sortedMerge(node* head1, node* head2)  
{   
	node* cur1 = head1, *cur2 = head2;
	node* tail1 = NULL, *tail2 = NULL;
	node* newHead = (cur1->data <= cur2->data ? head1 : head2);
	while (cur1 && cur2) {
		if (cur1->data <= cur2->data){
			while(cur1->next && cur1->next->data <= cur2->data) {
				cur1 = cur1->next;
			} 
			tail1 = cur1->next;
			cur1->next = cur2;
			cur1 = tail1;
		} else {
			while(cur2->next && cur1->data > cur2->next->data) {
				cur2 = cur2->next;
			}
			tail2 = cur2->next;
			cur2->next = cur1;
			cur2 = tail2;
		}
	}
	return newHead;
}

//OR 

ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
    if (!h1)
        return h2;
    if (!h2)
        return h1;
    
    ListNode* head = NULL;
    if (h1->val < h2->val) {
        head = h1;
        h1 = h1->next;
    } else {
        head = h2;
        h2 = h2->next;
    }
    
    ListNode* cur = head;
    while (h1 && h2) {
        if (h1->val < h2->val) {
            cur->next = h1;
            h1 = h1->next;
        } else {
            cur->next = h2;
            h2 = h2->next;
        }
        cur = cur->next;
    }
    
    if (h2)
        cur->next= h2;

    if (h1)
        cur->next = h1;
    return head;
}
