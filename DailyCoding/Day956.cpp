/******************************************************************************
[MEDIUM]

This problem was asked by Google.

Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct Compare
{
    bool operator () (ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }  
};

ListNode* helper(vector<ListNode*>& v)
{
    priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
    for (auto& a : v)
        pq.push(a);
        
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    
    while (!pq.empty()) {
        auto t = pq.top();
        pq.pop();
        
        cur->next = t;
        cur = cur->next;
        
        if (t->next)
            pq.push(t->next);
    }
    return dummy->next;
}

// main function
int main(){
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);
    
    ListNode* l2 = new ListNode(8);
    l2->next = new ListNode(11);
    l2->next->next = new ListNode(15);
    
    ListNode* l3 = new ListNode(5);
    l3->next = new ListNode(8);
    l3->next->next = new ListNode(11);
    
    ListNode* l4 = new ListNode(6);
    
    vector<ListNode*> v {l1, l2, l3, l4};
    
    ListNode* h = helper(v);
    while (h) {
        cout << h->val << " ";
        h = h->next;
    }

    return 0;
}
