/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

 
 */

Node* copyRandomList(Node* head) {
    map<Node*, Node*> m;
    Node* ptr = head;
    while (ptr) {
        m[ptr] =new Node(ptr->val);
        ptr = ptr->next;
    }
    ptr = head;
    while (ptr) {
        m[ptr]->next = m[ptr->next];
        m[ptr]->random = m[ptr->random];
        ptr = ptr->next;
    }
    return m[head];
}

// OR

Node* copyRandomList(Node* head) {
    if (!head)
        return NULL;
    
    Node* t1 = head;
    
    for (t1 = head; t1 != NULL; t1 = t1->next->next) {
        Node* t = new Node(t1->val);
        t->next = t1->next;
        t1->next = t;
    }
    
    Node* nHead = head->next;
    for (t1 = head; t1 != NULL; t1 = t1->next->next) {
        if (t1->random) 
            t1->next->random = t1->random->next;
    }
    
    for (t1 = head; t1 != NULL; t1 = t1->next) {
        Node* t = t1->next;
        t1->next = t->next;
        if (t->next)
            t->next = t->next->next;            
    }
    return nHead;
}
	
	
