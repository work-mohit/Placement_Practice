#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> s , ss;
    MinStack() {
        s = ss = {};
    }
    
    void push(int val) {
        s.push(val);
        if(ss.size() == 0 || val <= ss.top())
            ss.push(val);
        
    }
    
    int pop() {
        if(s.size() == 0)
            return -1;
        int ans = s.top();
        s.pop();
        if(ans == ss.top())
            ss.pop();
        return ans;
    }
    
    int top() {
        if(s.size() == 0)
            return -1;
        return s.top();
    }
    
    int getMin() {
        if(ss.size() == 0)
            return -1;
        return ss.top();
    }
};

int main(){
    MinStack sol;
    sol.push(34);
    sol.push(45);
    sol.push(1);
    sol.push(56);
    sol.pop();
    cout<<sol.getMin()<<endl;;
    sol.pop();
    cout<<sol.getMin();
    
    return 0;

}