int kthMoney(List *head , int k) {
	int n = 0;
    List* temp = head;
    while(temp != NULL){
        n++;
        temp = temp -> next;
    }
    int t = n-k;
    temp = head;
   while(t--){
       temp = temp->next;
   }
    return temp->data;
}