/*
Given a singly linked list of N nodes. The task is to find the middle of the linked list. For example, if given linked list is 1->2->3->4->5 then the output should be 3.
If there are even nodes, then there would be two middle nodes, we need to print the second middle element. For example, if given linked list is 1->2->3->4->5->6 then the output should be 4.

Example 1:

Input:
LinkedList: 1->2->3->4->5
Output: 3 
Explanation: 
Middle of linked list is 3.
Example 2: 

Input:
LinkedList: 2->4->6->7->5->1
Output: 7 
Explanation: 
Middle of linked list is 7.

Method: 
Traverse linked list using two pointers. Move one pointer by one and the other pointers by two. When the fast pointer reaches the end slow pointer will reach the middle of the linked list.

*/

int getMiddle(Node *head)
{
    Node* fast = head,*slow =head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}
