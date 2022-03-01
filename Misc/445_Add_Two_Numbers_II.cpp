// add link here

class Solution {

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1,stk2;
        ListNode* p1 = l1;
        
        while(p1!= NULL){
            stk1.push(p1->val);
            p1 = p1->next;
        }
        ListNode* p2 = l2;
        while(p2!=NULL){
            stk2.push(p2->val);
            p2 = p2->next;
        }
        
        int summ,carry = 0;
        ListNode *prev = NULL; 
        while(!stk1.empty() || !stk2.empty() || carry){
            
            summ = (stk1.empty()?0:stk1.top()) + (stk2.empty()?0:stk2.top()) + carry;
            carry = summ / 10;
            
            ListNode *curr = new ListNode(summ%10,prev);  // check the declaration of the ListNode
            prev = curr;
            
            if(!stk1.empty())stk1.pop();
            if(!stk2.empty())stk2.pop();
        }
        
        
      return prev; 
        
    }
}; 