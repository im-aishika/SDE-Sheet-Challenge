int findIntersection(Node *headA, Node *headB)
{
    Node* l1 = headA;
    Node* l2 = headB;
    int len1 = 0, len2 = 0;
    while(l1 != NULL || l2 != NULL){
        if(l1 != NULL) {
            len1 ++;
            l1 = l1->next;
        }
        
        if(l2 != NULL) {
            len2 ++;
            l2 = l2->next;
        }
    }
    
    int dif = abs(len1 - len2);
    l1 = headA;
    l2 = headB;
    if(len1 > len2) {
        while(dif--) {
            l1 = l1->next;
        }
    }
    else {
        while(dif--) {
            l2 = l2->next;
        }
    }
    
    while(l1 != NULL && l2 != NULL) {
        if(l1 == l2) return l1->data;
        l1 = l1->next;
        l2 = l2->next;
    }
    return -1;
}
