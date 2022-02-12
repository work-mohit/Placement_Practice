void sortInsert(stack<int>& s,int num){
    if(s.size() == 0 || (!s.empty() && s.top() < num)){
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    sortInsert(s, num);
    s.push(n);
}
void sortStack(stack<int> &s)
{
	if(s.size()==0)
        return;
    int data = s.top();
    s.pop();
    sortStack(s);
    sortInsert(s,data);
}