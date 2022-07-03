/*
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.

Example 1:

Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
Example 2:

Input:
N = 4
value[] = {1,2,3,4}
Output: 0
Explanation: The given linked list
is 1 2 3 4 , which is not a palindrome
and Hence, the output is 0.

METHOD 1 (Use a Stack) 


A simple solution is to use a stack of list nodes. This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from stack and compare data of popped node with currently visited node.
If all nodes matched, then return true, else false.
*/

// Using reversal
bool isPalindrome(ListNode* head) {
    ListNode* slow = head, *fast = head;
    
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    ListNode* prev = slow;
    slow = slow->next;
    prev->next = NULL;
    
    while (slow) {
        ListNode* temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }
    
    fast = head, slow = prev;
    while (slow) {
        if (fast->val != slow->val)
            return false;
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}

// Using recursion
bool check(ListNode* &head, ListNode* cur) {
    if (cur == NULL)
        return true;
    if (check(head, cur->next) && head->val == cur->val) {
        head = head->next;
        return true;
    }
    return false;
}

bool isPalindrome(ListNode* head) {
    return check(head, head);
}

// Using stack
bool isPalindrome(node *head)
{
	stack<int> s;
	node* cur = head;

	while(cur) {
		s.push(cur->data);
		cur = cur->next;
	}

	cur = head;

	while(cur) {
		if (cur->data != s.top())
			return false;
		cur = cur->next;
		s.pop();
	}
	return true;
}
