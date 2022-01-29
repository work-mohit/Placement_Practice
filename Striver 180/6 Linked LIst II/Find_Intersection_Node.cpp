// https://leetcode.com/problems/intersection-of-two-linked-lists/
// 78 ms 14.6ms
// better 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* intersect = NULL;
        int cntA = 0, cntB = 0;
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempA != NULL){
            cntA++;
            tempA = tempA->next;
        }
        while(tempB != NULL){
            cntB++;
            tempB = tempB->next;
        }
        int step;
        tempA = headA;
        tempB = headB;
        if(cntA > cntB){
            while(cntA != cntB){
                tempA = tempA->next;
                cntA--;
            }
        }else{
            while(cntB != cntA){
                tempB = tempB->next;
                cntB--;
            }
        }
        while(tempA != NULL || tempB != NULL){
            if(tempA == tempB)
                return tempA;
            tempA = tempA->next;
            tempB = tempB->next;
        }
        
        return intersect;
    }
};

// Brute force
// 993 ms 14.5mb
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { 
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        while(tempB != NULL){
            while(tempA != NULL){
                if(tempA == tempB){
                    return tempB;    
                }   
                tempA =tempA -> next;
            }
            tempA = headA;
            tempB = tempB->next;
        }
        
        return NULL;
    }
};
// Optimal and best with concise code
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) { 
        ListNode *first = headA; 
        ListNode* second = headB;
        while(first != second){
            first = first?first->next:headB;
            second = second?second->next:headA;
            
        }
        
        return first;
    }
};