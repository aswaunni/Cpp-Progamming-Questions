/*
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
#include <unordered_map>
class Solution
{
	public:
		//Function to remove a loop in the linked list.
		void removeLoop(Node* head)
		{
			unordered_map<Node*, int> m;
			Node* cur = head, *prev = NULL;

			while(cur) {
				if (m.find(cur) == m.end()) {
					m[cur]++;
					prev = cur;
					cur = cur->next;
				} else {
					prev->next = NULL;
					break;
				}
			}
		}
};
