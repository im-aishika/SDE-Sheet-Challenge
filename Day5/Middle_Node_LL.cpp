//Aproach 1: Naive or the brute force approach

Node *findMiddle(Node *head) {
    // Write your code here
    int len = 0;
    Node* p =  head;
    while(p != NULL) {
        len ++;
        p = p->next;
    }
    
    int midNode = (len/2);
    p = head;
    while(midNode--) {
        p = p->next;
    }
    return p;
}


//Approach 2: Using 2 pointers: slow and fast

Node *findMiddle(Node *head) {
    // Write your code here
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast =fast->next->next;
    }
    
    return slow;
}
