// Break whole code in three part :
// 1 -> Clone just linked list with next pointer
// 2 -> make a hashmal which stores old to new node
// 3 -> now add random pointer with the help of the hashmap

// **This is what i mean by mapping **

// Old :  1 -> 2 -> 3 -> 4 -> 5 ->NULL
// 	      |    |    |    |    |
// New:   1 -> 2 -> 3 -> 4 -> 5 ->NULL

// Now  i traverse through old LL and do this !
// clonetemp -> random = mapping[temp->random];


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // clone list
        if(head == NULL)
            return NULL;
        unordered_map<Node*,Node*> mapping;
        Node* temp = head;
        Node* cloneList = new Node(0);
        Node* clonetemp = cloneList;
        while(temp){
            clonetemp->next = new Node(temp->val);
            
            clonetemp = clonetemp->next;
            mapping[temp] = clonetemp;           // mapping part
            temp = temp->next;
        }
        
        temp = head;
        clonetemp = cloneList->next;
        while(temp){
            clonetemp -> random = mapping[temp->random];
            temp = temp -> next;
            clonetemp = clonetemp->next;
        }
            
        return cloneList->next;      
        
    }
};
//////////////////////////////////////////////////////////////////////////////////////////////
class Solution
{
    public:
    Node *copyList(Node *head)
    {
        if(head == NULL)
            return NULL;
            
        // CLONE LIST
        
        Node* temp = head;
        Node* cloneList = new Node(0);
        Node* clonetemp = cloneList;
        
        while(temp){
            clonetemp->next = new Node(temp->data);
            clonetemp = clonetemp->next;
            temp = temp->next;
        }
        
        // ADD CLONE NODES IN B/W OLD NODES
        
    
        temp = head;
        clonetemp = cloneList->next;
        
        Node* save1 = NULL;
        Node* save2 = clonetemp;
        while(temp != NULL || clonetemp != NULL){
            save1 = temp -> next;
            temp -> next = clonetemp;
            temp = save1;
            
            save2 = clonetemp->next;
            clonetemp->next = temp;
            clonetemp = save2;
        }
        
        // now position random pointer
        
        temp = head;
        while(temp != NULL){
            if(temp->next != NULL){
                 temp->next->arb = temp->arb? temp->arb->next : temp->arb;
            }
            temp = temp->next->next;
        }
        
        // reverse the old list to back 
        
        temp = head;
        clonetemp = cloneList->next;
        
        while(temp != NULL && clonetemp != NULL){
            temp->next = clonetemp ->next;
            temp = temp ->next;
            
            if(temp != NULL)
                clonetemp->next = temp->next;
            
            clonetemp = clonetemp->next;
        }
        
            
        return cloneList->next;
    }

};

