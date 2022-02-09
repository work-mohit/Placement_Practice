class Solution {
private:
    ListNode* getMid(ListNode* head){
        ListNode *slow = head, *fast = head -> next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* s1, ListNode* s2){
        if(s1 == NULL)   //
            return s2;
        if(s2 == NULL) //
            return s1;
        ListNode *ptr = new ListNode(0);
        ListNode *temp = ptr;
        while(s1!= NULL && s2 != NULL){
            if(s1->val <= s2 ->val){
                temp->next = s1;
                temp = s1;///
                s1 = s1->next;
            }    
            else{
                temp->next = s2;
                temp = s2;     //
                s2 = s2->next;
            }
        }
        while(s1 != NULL){
            temp->next =s1;
            temp = s1;    //
            s1 = s1->next;
        }
        while(s2 != NULL){
            temp -> next = s2;
            temp = s2;     //
            s2 = s2->next;
        }
        return ptr->next;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        // break list into two parts after finding middle
        
        ListNode* middle = getMid(head);
        ListNode* left = head;
        ListNode* right = middle->next;
        middle->next = NULL;
        
        // recursive call to sort 
        left = sortList(head); 
        right = sortList(right);
        
        // merge both left and right
        ListNode* res = merge(left ,right);
        
        return res;
    }
};


/////////////////////////////////////////////////////////////////////////////


