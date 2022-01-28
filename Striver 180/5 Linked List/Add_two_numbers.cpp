// https://leetcode.com/problems/add-two-numbers/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int summ, carry=0;
        ListNode newlist(0);
        ListNode *temp = &newlist;
        while(l1 || l2 || carry){
            summ = (l1? l1->val :0) +(l2? l2->val :0) + carry; 
            temp->next = new ListNode(summ % 10);
            carry = summ / 10;
            temp = temp->next;
            l1 =(l1)?l1->next:l1;
            l2 =(l2)?l2->next:l2;
            
        }        
        return newlist.next; // bcz at first we have 0 and we add new node to new digit .
    
    }
};