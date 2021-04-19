/*
   struct Node {
   int data;
   struct Node *next;
   Node(int x) {
   data = x;
   next = NULL;
   }
   }*head;
 */


class Solution
{
	public:
		//Function to delete a node without any reference to head pointer.
		void deleteNode(Node *del)
		{
			Node* prev = NULL;
			if (!del)
				return;

			while (del->next) {
				del->data = del->next->data;
				prev = del;
				del = del->next;
			}
			prev->next = NULL;
		}

};
