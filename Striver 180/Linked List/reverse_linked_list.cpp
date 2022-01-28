// https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* nxt = head;
        while(head != NULL){
            nxt = head->next;
            head->next = prev;
            prev = head;
            head =nxt;
        }
        return prev;
        
    }
};