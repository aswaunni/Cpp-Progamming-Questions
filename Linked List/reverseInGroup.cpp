/*
Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

Example 1:

Input:
LinkedList: 1->2->2->4->5->6->7->8
K = 4
Output: 4 2 2 1 8 7 6 5 
Explanation: 
The first 4 elements 1,2,2,4 are reversed first 
and then the next 4 elements 5,6,7,8. Hence, the 
resultant linked list is 4->2->2->1->8->7->6->5.


 we have used a stack which will store the nodes of the given linked list. Firstly, push the k elements of the linked list in the stack. Now pop elements one by one and keep track of the previously popped node. Point the next pointer of prev node to top element of stack. Repeat this process, until NULL is reached.
*/

node *reverse (struct node *head, int k)
{ 
    node* prev = NULL;
    node* next;
    node* curr = head;
    int i = 0;
    while (i < k && curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        i++;
    }
    if (curr)
        head->next = reverse(curr, k);
    return prev;
}

//OR

node* reverse(node* head, int k)  
{   
	node* cur = head, *prev = NULL;
	stack<node*> s;
	while (cur) {
		int count = 0;

		while (cur && count < k) {
			s.push(cur);
			cur = cur->next;
			count++;
		}

		while(s.size() > 0) {
			if(!prev) {
				prev = s.top();
				head = prev;
				s.pop();
			} else {
				prev->next = s.top();
				prev = prev->next;
				s.pop();
			}
		}
	}

	prev->next = NULL;

	return head;
}
