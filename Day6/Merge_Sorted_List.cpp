#include <bits/stdc++.h> 

Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    Node<int>* dummy = new Node<int>(-1);
    Node<int>* tail = dummy;
    
    while(l1 && l2) {
        if(l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    
    tail->next = l1 ? l1 : l2;
    return dummy->next;
}
