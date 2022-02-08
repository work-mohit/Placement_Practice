class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp =head;
        while(temp!=NULL)
        {               
        	while(temp->next && temp->val == temp->next->val) {
        		temp->next = temp->next->next;
        	}
        	temp = temp->next;
        }
        return head;
            
        
    }
};