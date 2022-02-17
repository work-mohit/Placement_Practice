queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    int temp = k;
    while(temp--){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    int x = q.size() - k;
    while(x--){
        int val = q.front();
        q.pop(); 
        q.push(val);
    }
    return q;
}