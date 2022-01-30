// You are given the head of a linked list containing unique integer values 
// and an integer array nums that is a subset of the linked list values.

// Return the number of connected components in nums where two values are 
// connected if they appear consecutively in the linked list.

// Input: head = [0,1,2,3], nums = [0,1,3]
// Output: 2
// Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected components.

// Input: head = [0,1,2,3,4], nums = [0,3,1,4]
// Output: 2
// Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3, 4] are the two connected components.

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> ss;
        ListNode* curr = head;

        int ans=0;
        for(auto p: nums) ss.insert(p);
        while(curr){
            if(ss.find(curr->val) != ss.end()){
                ans++;
                while(curr->next && ss.find(curr->val) != ss.end()) 
                    curr=curr->next;
                curr=curr->next;
            }
            else curr = curr->next;
        }
        return ans;
    }
};
