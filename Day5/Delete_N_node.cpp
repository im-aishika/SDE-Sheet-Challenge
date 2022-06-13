void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    
    LinkedListNode<int> *p = node;
    LinkedListNode<int> *q = node;
    LinkedListNode<int> *t = node;
    
    while(p != NULL) {
        p = p->next;
        if(p == NULL) {
            break;
        }
        q->data = p->data;
        t = q;
        q = p;
    }
    t->next = NULL;
}
