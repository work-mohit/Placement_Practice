#include<bits/stdc++.h>
using namespace std;
void deleteMiddle(stack<int>& s){
    int index;
    if(s.size() & 1)
        index = s.size()/2;
    else
        index = s.size()/2 -1;

    stack<int> s1;
    
    while(index--){    
        s1.push(s.top());
        s.pop();
    }
    s.pop();
    while(s1.size()){
        s.push(s1.top());
        s1.pop();
    }
}
 
////////////////////////////////////////////////////////////////////////////////////
void solve(stack<int>& s, int count, int size){
    if(count == size/2){
        s.pop();
        return;
    }
        

    int index = s.top();
    s.pop();
    solve(s,count+1, size);
    s.push(index);
}
void deleteMiddleByLoveBabber(stack<int>& s){
    int count = 0;
    int N = s.size();
    solve(s, count, N);
}
/////////////////////////////////////////////////////////////////////////
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    s.push(45);
    s.push(56);
    s.push(4);
    s.push(8);
    s.push(9);
    s.push(4);
    s.push(79);
    // deleteMiddle(s);  // 6 elements so delete (1 2 3 4 5 6) 3rd one
    deleteMiddleByLoveBabber(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    
    return 0;
}