// https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
//  This problem can have 3 methods:
// 1 . Using sort 
// 2 . Using Min or Max heap
// 3 . Using Quick Select

#include<bits/stdc++.h>
using namespace std;

// 1. Using Sort method
// int kthSmallest(int arr[], int n, int k)
// {
//     // Sort the given array
//     sort(arr, arr + n);
 
//     // Return k'th element in the sorted array
//     return arr[k - 1];
// }

// TC = O(N log N) 

//  SC = O(1)

void kthsmallestElement(int arr[], int n, int k){
    sort(arr, arr+n);   // O(N * log N)
    cout<<arr[k-1]<<endl;
    return;
}

// TC = O(N + klog N) average O(N) in worst case 
// SC = O(N) 
void kthSmallestUsingMinHeap(int arr[],int n , int k){
    priority_queue <int, vector<int>, greater<int> > pq;
    for ( int i = 0; i < n; i++)
        pq.push(arr[i]);
    while(pq.empty() == false && k--){
        pq.pop();
    }
    cout<<pq.top()<<endl;
}
void kthSmallestUsingMaxHeap(int arr[],int n , int k){
    priority_queue <int> pq;
    for ( int i = 0; i < n; i++)
        pq.push(arr[i]);
    int q = n-k;
    while(pq.empty() == false && q--){
        pq.pop();
    }
    cout<<pq.top()<<endl;
}
void kthHighestUsingMaxHeap(){
    // to be written
}
void kthHighestUsingMaxHeap(){
    // to be written
}
int main(){
    int arr[] = {1, 5, 9, 6,86,92,4,6};
     
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 8;
    
    kthsmallestElement(arr, n, k);
    kthSmallestUsingMinHeap(arr, n ,k);
    kthSmallestUsingMaxHeap(arr, n , k);
    kthHighestUsingMinHeap(arr, n, k);
    kthHighestUsingMaxHeap(arr, n, k);
    
    return 0;
}