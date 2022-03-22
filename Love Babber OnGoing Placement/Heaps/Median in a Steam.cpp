#include<bits/stdc++.h>
int signum(int a , int b){
    if(a == b)
   		return 0;
    else if (a > b)
        return 1;
    else 
        return -1;
}
void call_median(int element ,
   							 priority_queue<int> &maxHeap,
   										 priority_queue<int, vector<int> , greater<int>> &minHeap, int &M){
    
    switch(signum(maxHeap.size(), minHeap.size())){
        // both equal
        case 0:
          	if(element > M){
                minHeap.push(element);
                M = minHeap.top();
            }else{
                maxHeap.push(element);
                M = maxHeap.top();
            }
            break;
        // maxheap > minheap
        case 1:
           if(element > M){
               minHeap.push(element);
               M = (minHeap.top() + maxHeap.top())/2;
           }else{
               minHeap.push(maxHeap.top());
               maxHeap.pop();
               maxHeap.push(element);
               M = (minHeap.top() + maxHeap.top())/2; 
           }
           break;
        case -1:
            if(element > M){
               maxHeap.push(minHeap.top());
               minHeap.pop();
               minHeap.push(element);
               M = (minHeap.top() + maxHeap.top())/2;
           }else{
               maxHeap.push(element);
               M = (minHeap.top() + maxHeap.top())/2;
           }
           break;
    }
}

vector<int> findMedian(vector<int> &arr, int n){
	vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int> , greater<int>> minHeap;
    int median = 0;
    for(int i = 0; i < n; i++){
        call_median(arr[i],maxHeap,minHeap, median);
        ans.push_back(median);
    }
    return ans;
}
