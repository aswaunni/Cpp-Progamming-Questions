/*
You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.

Example 1:

Input:
N = 3
value[] = {1,3,4}
X = 2
Output: 1
Explanation: The link list looks like
1 -> 3 -> 4
     ^    |
          |____|    
	  A loop is present. If you remove it 
	  successfully, the answer will be 1. 


*/

/*
structure of linked list node:

struct Node
{
	int data;
	Node* next;

	Node(int val)
	{
		data = val;
		next = NULL;
	}
};

*/

class Solution
{
	public:
		//Function to remove a loop in the linked list.
		void removeLoop(Node* head)
		{
			Node* slow = head, *slow_prev = NULL, *fast = head;

			while(slow && fast && fast->next) {
				slow_prev = slow;
				slow = slow->next;
				fast = fast->next->next;

				if (slow == fast)
					break;
			}

			if (slow == fast) {
				slow = head;

				if (fast == slow) {
					while (fast->next != slow)
						fast = fast->next;
				} else {
					while (slow->next != fast->next) {
						slow = slow->next;
						fast = fast->next;
					}
				}
				fast->next = NULL;
			}
		}
};
