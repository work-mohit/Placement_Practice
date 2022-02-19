void reverseQ(queue<int>& q){
    if(q.empty()){
        return;
    }
    int ele = q.front();
    q.pop();
    reverseQ(q);
    q.push(ele);
}

queue<int> rev(queue<int> q)
{
    reverseQ(q);
    return q;
}

////////////////////////////////////////////////////////////////
void reverseQ(queue<int>& q){
    if(q.empty()){
        return;
    }
    int ele = q.front();
    q.pop();
    reverseQ(q);
    q.push(ele);
}
// tail call optimization

void auxReverseQ(queue<int>& q){
    reverseQ(q);
}
queue<int> rev(queue<int> q)
{
    auxReverseQ(q);
    return q;
}