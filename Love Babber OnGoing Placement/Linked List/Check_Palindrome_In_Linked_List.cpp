// TC: O(N) SC:O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        queue<int> q;
        ListNode * curr=head;
        while(curr!=NULL)
        {
            st.push(curr->val);
            q.push(curr->val);
            curr=curr->next;
        }
        while(!st.empty())
        {
            if(st.top()!=q.front())
                return false;
            st.pop();
            q.pop();
        }
        return true;
    }
};
// TC: O(N) SC: O(1)
class Solution {
private:
    ListNode* reverse(ListNode* head){
        ListNode *curr = head, *prev = NULL, *next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr-> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
            return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* middle = slow;
        
        middle->next = reverse(middle->next);
        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;
        
        while(head2 != NULL){
            if(head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};