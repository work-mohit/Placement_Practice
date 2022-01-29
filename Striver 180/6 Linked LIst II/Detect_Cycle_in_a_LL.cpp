class Solution {
public:
    bool hasCycle(ListNode *head) {
        // 8ms
        if(head == NULL)return false;
        ListNode *slow = head, *fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
        
        // 17ms
        // while(head != NULL){
        //     head->val = INT_MIN;
        //     head = head->next;
        //     if(head != NULL && head->val == INT_MIN)
        //         return true;
        // }
        // return false;  
    }
};