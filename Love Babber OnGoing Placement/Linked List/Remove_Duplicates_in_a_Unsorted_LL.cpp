class Solution
{
    public:

    Node * removeDuplicates( Node *head) 
    {
     // your code goes here
     if(head == NULL || head ->next == NULL)
        return head;
     unordered_map<int , int> mapping;
     
     Node* prev = head;
     Node* curr = head->next;
     mapping[prev->data] = 1;
     
     while(curr != NULL){
        if(mapping[curr->data] ){
            prev ->next = curr->next;
            free(curr);
        }
        else{
            mapping[curr->data] = 1;
            prev = prev->next;
        }
            
        curr = curr -> next;
     }
     
     return head;
     
    }
};


