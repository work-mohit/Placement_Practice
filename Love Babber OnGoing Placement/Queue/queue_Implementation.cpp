#include<bits/stdc++.h>
using namespace std;
class Queue{
    int *arr;
    int qfront;
    int rear;
    int size;
public:
    Queue(){
        size = 10000;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }
    void push(int ele){
        if(rear == size)
            cout<<"Queue is full.";
        else
            arr[rear++] = ele;
    }
    int pop(){
        if(qfront == rear)
            return -1;
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear){
                qfront = rear = 0;
            }
            return ans;
        }
        
    }
    bool isEmpty(){
        if(qfront == rear)
            return true;
        return false;
    }
    int front(){
        if(qfront == rear)
            return -1;
        else{
            return arr[qfront];
        }
    }
    int qsize(){
        return rear - qfront ;
    }
};
int main(){
    Queue q;
    q.push(45);
    q.push(38);
    q.push(33);
    q.push(33);
    cout<<q.pop()<<endl;
    cout<<q.front()<<endl;
    cout<<q.isEmpty()<<endl;
    cout<<q.qsize()<<endl;
    
    return 0;
}