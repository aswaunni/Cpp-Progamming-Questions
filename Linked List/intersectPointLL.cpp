/*
Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.

 

 Example 1:

 Input:
 LinkList1 = 3->6->9->common
 LinkList2 = 10->common
 common = 15->30->NULL
 Output: 15


 Get count of the nodes in the first list, let count be c1.
 Get count of the nodes in the second list, let count be c2.
 Get the difference of counts d = abs(c1 - c2)
 Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes 
 Then we can traverse both the lists in parallel till we come across a common node. (Note that getting a common node is done by comparing the address of the nodes)

*/



/* Linked List Node
   struct Node {
   int data;
   struct Node *next;
   Node(int x) {
   data = x;
   next = NULL;
   }
   }; */


int count(Node* head)
{
	int count = 0;
	Node* cur = head;

	while (cur) {
		count++;
		cur = cur->next;
	}
	return count;
}

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2)
{
	int count1 = count(head1);
	int count2 = count(head2);

	int d = abs(count1 - count2);

	Node* cur1 = (count1 > count2 ? head1 : head2);
	Node* cur2 = (count1 > count2 ? head2 : head1);

	for (int i = 0; i < d; i++)
		cur1 = cur1->next;

	while (cur1 && cur2) {
		if (cur1 == cur2)
			return cur1->data;
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return -1;

}
