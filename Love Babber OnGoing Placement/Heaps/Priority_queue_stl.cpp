#include<bits/stdc++.h> 
using namespace std;

void showpq(priority_queue<int> gq)
{
    priority_queue<int> g = gq;
    while (!g.empty()) {
        cout <<" "<< g.top();
        g.pop();
    }
    cout << '\n';
}

void showpqMin(priority_queue<int , vector<int> , greater<int>> gq)
{
    priority_queue<int , vector<int> , greater<int>> g = gq;
    while (!g.empty()) {
        cout <<" "<< g.top();
        g.pop();
    }
    cout << '\n';
}

int main(){
    priority_queue<int> pq;
    pq.push(38);
    pq.push(45);
    pq.push(9);
    pq.push(42);
    pq.push(80);
    pq.pop();
    pq.pop();
    showpq(pq);
    // min heap
    cout<<endl;
    priority_queue<int , vector<int> , greater<int>> g;
    g.push(38);
    g.push(45);
    g.push(9);
    g.push(42);
    g.push(80);
    cout<<g.size()<<endl;
    showpqMin(g);
    
    return 0;
}