#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> * revLL(LinkedListNode<int> * head) {
    LinkedListNode<int> *p = head;
    LinkedListNode<int> *q = NULL;
    
    while(p != NULL) {
        LinkedListNode<int> * t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    return q;
}
bool isPalindrome(LinkedListNode<int> *head) {
    //edge case: incase the head is null or a single node LL
    if(head == NULL || head->next == NULL) return true;
    //edge case: checking for 2 nodes LL
    if(head->next->next == NULL) {
        if(head->data == head->next->data) return true;
        return false;
    }
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    
    while(fast->next != NULL && fast->next->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    //at this junction the slow points to the middle of the LL
    fast = slow->next;
    slow->next = revLL(fast);
    slow = slow->next;
    LinkedListNode<int> *dummy = head;
    
    while(slow != NULL) {
        if(slow->data != dummy->data) return false;
        slow = slow->next;
        dummy = dummy->next;
    }
    return true;
}
