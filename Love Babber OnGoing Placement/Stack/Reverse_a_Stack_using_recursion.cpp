void insertAtBottom(stack<int>& s, int x){
    if(s.size() ==0){
        s.push(x);
        return;
    }  
    int data = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(data);
}
void reverseStack(stack<int> &s) {
    if(s.size() ==0)
        return;
    int x = s.top();
    s.pop();
    reverseStack(s);	
    insertAtBottom(s,x);
}