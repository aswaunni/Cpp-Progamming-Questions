/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/

ListNode* mergeKLists(vector<ListNode*>& lists) {
    multimap<int, ListNode*> mp;
    for (auto &node: lists) {
        while (node) {
            mp.insert({node->val, node});
            node = node->next;
        }
    }
    ListNode* head = nullptr;
    ListNode* temp = nullptr;
    for (auto [key, value]: mp) {
        if (!head) {
            head = value;
            temp = head;
            continue;
        }
        temp->next = value;
        temp = temp->next;
    }
    return head;
}

//OR 

struct compare
{
    bool operator() (ListNode* &a, ListNode* &b)
    {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*,vector<ListNode*>,compare>pq;

    for(ListNode* x:lists){
        if (x)
            pq.push(x);
    }  
    
    ListNode* head=NULL;
    ListNode* tail=NULL;
    
    while(!pq.empty()){
        
        ListNode* val=pq.top();
        pq.pop();
        
        if(head==NULL){
            tail=val;
            head=val;
        } else {
            tail->next=val;
            tail=tail->next;   
        }
            
        if(val->next)
            pq.push(val->next);

    }
    return head;
}
