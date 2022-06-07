//Add Two numbers as linked list (Leetcode 2)
// [2,4,3] + [5,6,4] = [7,0,8]

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy =  new ListNode();
        ListNode* tail = dummy;
        
        int car = 0;
        while(l1 != NULL || l2 != NULL || car != 0) {
            int sum = 0;
            
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += car;
            car = sum / 10;
            sum %= 10;
            
            ListNode* newNode = new ListNode(sum);
            tail->next = newNode;
            tail = newNode;
        }
        return dummy->next;
    }
};


//Add two numbers as linked list in reverse way (Leetcode 445)

class Solution {
private:
    ListNode* revLL(ListNode* head) {
        ListNode* p = head;
        ListNode* q = NULL;
        while(p != NULL) {
            ListNode* t = p->next;
            p->next = q;
            q = p;
            p = t;
        }
        return q;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = revLL(l1);
        l2 = revLL(l2);
        
        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;
        int car = 0;
        
        while(l1 != NULL || l2 != NULL || car != 0) {
            int sum = 0;
            
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += car;
            car = sum / 10;
            sum %= 10;
            
            ListNode* newNode = new ListNode(sum);
            tail->next = newNode;
            tail = newNode;
        }
        
        return revLL(dummy->next);
    }
};
