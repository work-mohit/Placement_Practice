class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1);  // it's better to track so define it necessarily
        preheader->next = head;
        ListNode *cur = preheader, *nex, *pre = preheader;
        while(cur = cur->next)     // first count the num of nodes 
            num++;
        while(num>=k) {            // if no of nodes is > k then reverse 
            cur = pre->next;               // apply reverse logic for k = 3, 1 2 3 4 5 6 7 8 => 3 2 1 6 5 4 7 8
            nex = cur->next;               // first take  1 2 3 and reverse it 
            for(int i=1;i<k;++i) {          //  it change to 2 1 3
                cur->next=nex->next;        // then change to 3 2 1 
                nex->next=pre->next;        // and again we will do this for 4 5 6 
                pre->next=nex;
                nex=cur->next;
            }
            pre = cur;
            num-=k;
        }
        
        return preheader->next;
    }
};