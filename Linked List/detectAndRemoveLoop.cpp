#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    Node(int i) {
        data = i;
        next = NULL;    
    }
    Node(int i, Node* n) {
        data = i;
        next = n;    
    }
    Node* next;
    int data;
};

void insertLL(Node* &head, int i) {
    Node* temp = head;
    Node* n = new Node(i);
    
    if(head == NULL)
        head = n;
    while(temp->next)
        temp = temp->next;
    temp->next = n;
}

void printLL(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* reverseKLL(Node* head, int k) {
    Node* cur = head, *prev = NULL, *next;
    int cnt = 0;

    while(cur && cnt < k) {
       next = cur->next;
       cur->next = prev;
       prev = cur;
       cur = next;
       cnt++;
    }

    if (cur)
        head->next = reverseKLL(cur, k);
    return prev;
}

void* createCycle(Node* head) {
    Node* temp = head;
    while(temp->next)
        temp = temp->next;
    temp->next = head->next->next;
}

bool detectCycle(Node* head) {
    Node* slow = head, *fast = head;

    while (fast->next && fast) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    return false;
}

void removeCycle(Node* &head) {
    Node* slow = head, *fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    slow = head;

    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    fast->next = NULL;
}

int main()
{
    Node* head = new Node(1);
    insertLL(head, 2);
    insertLL(head, 3);
    insertLL(head, 4);
    insertLL(head, 5);
    insertLL(head, 6);

    createCycle(head);

    removeCycle(head);
    printLL(head);

    return 0;
}
