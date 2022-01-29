// https://leetcode.com/problems/remove-nth-node-from-end-of-list
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return head;
        ListNode* temp = head;
        int cnt = 0;
        while(temp != NULL){
            temp= temp->next;
            cnt++;
        }
        
        int nodeFromStart = cnt - n;
        temp = head;
        while(--nodeFromStart > 0){   // it will go till one step back from the element we want to remove
            temp = temp->next;
        }  
        if(cnt - n <= 0)   // it's for base case where if n == cnt means first element so that time we provide head->next;
            head = temp -> next;
        else
            temp -> next = temp->next->next;  
        
        return head;
    }
    
};