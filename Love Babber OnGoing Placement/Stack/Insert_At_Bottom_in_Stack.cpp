void solve(stack<int>& s,int x){
    if(s.size()== 0){
        s.push(x);
        return;
    }
        
    int data = s.top();
    s.pop();
    solve(s,x);
    s.push(data);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}
