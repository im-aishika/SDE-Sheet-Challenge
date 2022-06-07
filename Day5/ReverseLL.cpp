#include <bits/stdc++.h> 
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    LinkedListNode<int>* p = head;
    LinkedListNode<int>* q = NULL;
    
    while(p != NULL) {
        LinkedListNode<int> * temp = p->next;
        p->next = q;
        q = p;
        p = temp;
    }
    return q;
}
