#include <bits/stdc++.h> 

Node *firstNode(Node *head)
{
    //edge case for no cycle in the linked list
    if(head == NULL || head->next == NULL) return NULL;
    
	Node* slow = head;
    Node* fast = head;
    
    do {
        slow = slow->next;
        if(fast == NULL || fast->next == NULL) return NULL;
        fast = fast->next->next;
    }
    while(slow != fast);
    
    fast = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
