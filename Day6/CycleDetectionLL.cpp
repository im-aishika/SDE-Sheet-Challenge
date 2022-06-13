//Approach 1: Using hashMap
bool detectCycle(Node *head)
{
    if(head == NULL || head->next == NULL) return false;
	map<Node*, int> mpp;
    Node *p;
    for(p = head; p != NULL; p = p->next){
        if(mpp.find(p) != mpp.end()) {
            return true;
        }
        mpp[p] ++;
    }
    return false;
}


//Approach 2: Flyod Tortoise Hare algorithm for cycle detection
bool detectCycle(Node *head)
{
	if(head == NULL || head->next == NULL) return false;
    
    Node* slow = head;
    Node* fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
