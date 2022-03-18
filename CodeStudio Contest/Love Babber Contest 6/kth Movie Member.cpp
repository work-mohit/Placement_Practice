/*
    You are standing in queue to buy the latest Batman movie ticket. You noticed the queue looked like and singly LinkedList.
    Each person has some amount of money with them, you are bored, and you want to 
    find the amount of money the person is standing at the ‘Kth’ of the queue from the back.

    N = 4,  K = 2  
    NODE = 1 -> 2 -> 3 -> 4
    In the following example, the 2nd person from the back has ‘3’ units of money.

    ohh it's just a simple problem of linked list man!!
    don't get stuck here

 */
int kthMoney(List *head , int k) {
	int n = 0;
    List* temp = head;
    while(temp != NULL){   // traverse whole list and count the element 
        n++;
        temp = temp -> next;
    }
    int t = n-k;    // now go till n - k
    temp = head;
   while(t--){
       temp = temp->next;
   }
    return temp->data;
}