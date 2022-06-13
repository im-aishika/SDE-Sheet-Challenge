#include <bits/stdc++.h> 

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    //edge case: i.e the linked list is NULL
    if(head == NULL) return NULL;
    
    LinkedListNode<int> *p = head;
    int len = 0;
    
    //finding the length of the linked list
    while(p != NULL) {
        len ++;
        p = p->next;
    }
    
    int l = len-k;
    p = head;
    LinkedListNode<int> *q = head;
    //if the node to be deleted is simply the
    //head of the linked list
    if(l == 0) return head->next; 
    
    for(int i = 0; i < len; i++) {
        if(i == l) {
            q->next = p->next;
            break;
        }
        q = p;
        p = p->next;
    }
    return head;
}
