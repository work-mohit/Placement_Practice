// Given an sorted array find the total occurence of an element 
// if array is not present return -1
#include<bits/stdc++.h> 
using namespace std;
int firstOcc(int *arr, int n , int k){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(arr[mid] == k){
            ans = mid;
            e = mid-1;
        }else if(arr[mid] <k){
            s = mid +1;
        }else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int lastOcc(int *arr, int n, int k){
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;
    int ans = -3;       // just for calculation so i can return -1 in the total result when a element is not present 
    while(s <= e){
        if(arr[mid] == k){
            ans = mid;
            s = mid+1;
        }else if(arr[mid] <k){
            s = mid +1;
        }else{
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int totalOccurence(int *arr, int n , int k){
    return lastOcc(arr, n, k) - firstOcc(arr, n, k) + 1;
}

int main(){
    int arr[10] = {3,4,4,4,5,5,5,5,5,6};
    int n = 10;
    int k = 7;
    cout<<totalOccurence(arr,n , k);
    return 0;
}
