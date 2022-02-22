/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

 

Example 1:


Input: head = [1,2,3,4]
Output: [1,4,2,3]
Example 2:


Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/

void reorderList(ListNode* head) {
    stack<ListNode*> q;
    ListNode* t = head;
    while(t){
        q.push(t);
        t = t->next;
    }
    
    int n = q.size();
    
    t = head;
    for (int i = 0; i < (n)/2; i++) {
        ListNode* x = t->next;
        t->next = q.top();
        t->next->next = x;
        q.pop();
        t = x;
    }
    t->next = NULL;
}

// OR

    ListNode* reverseList(ListNode* head){
    if(head==NULL)
        return NULL;
    ListNode* prev=NULL,*curr=head;
    while(curr){
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
    }
    return prev;
}
void reorderList(ListNode* head) {
    if(head==NULL||head->next==NULL||head->next->next==NULL)
        return ;
    //find the middle of list
    ListNode* slow=head,*fast=head->next;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* secondHead=slow->next;
    slow->next=NULL;
    //reverse the second list
    secondHead=reverseList(secondHead);
    ListNode* curr1=head,*curr2=secondHead;
    
    //linking list
    while(curr1 && curr2){
        ListNode* temp1=curr1->next;
        ListNode* temp2=curr2->next;
        curr1->next=curr2;
        curr2->next=temp1;
        curr1=temp1;
        curr2=temp2;
    }
}
