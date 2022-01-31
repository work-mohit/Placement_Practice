class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *temp = head, *prev = NULL;
        if(!head)
            return head;
        int cnt = 0;
        while(temp->next){
            cnt++;
            temp = temp->next;
        }
        cnt++;
        temp->next = head;
        k = k%cnt;
        if(cnt == k)
            return head;
        int d = cnt - k + 1;    // d = cnt - k and put cnt initally 1
        while(d--){
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        return temp;
    }
};

// Another Solution with better coding
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;
        ListNode *cur = head;
        int len = 1;
        while (cur->next && ++len)
            cur = cur->next;
        cur->next = head;
        k = len - k % len;
        while (k--) cur = cur->next;
        head = cur->next;
        cur->next = nullptr;
        return head;
        
    }
};