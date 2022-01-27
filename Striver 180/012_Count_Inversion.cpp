#include<bits/stdc++.h>
using namespace std;
int mergeAndCount(int arr[] , int temp[], int low , int mid, int high){
    int i ,j ,k;
    int inv_count = 0;

    i = low;  // for array
    j = mid;    
    k = low;  // for result subarray

    while((i <= mid-1) &&  (j <= high)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];

            inv_count += (mid-i);
        }
    }
    while(i <= mid-1){
        temp[k++] = arr[i++];
    }
    while( j <= high){
        temp[k++] = arr[j++];
    }
    // copy back to the original array to reflect sorted order
    for (i = low; i<= high; i++)
        arr[i] = temp[i];

    return inv_count;
}
int mergeSort(int arr[], int temp[], int low , int high){
    int mid , inv_count = 0;
    
    if(low < high){
        mid = (high + low)/2;

        inv_count += mergeSort(arr,temp , low , mid);
        inv_count += mergeSort(arr,temp , mid+1, high);

        inv_count += mergeAndCount(arr, temp, low, mid+1,high);
    }
    return inv_count;
}
int main(){
    int arr[] = {1,4,6,2,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    int num= mergeSort(arr, temp, 0 , n-1);
    cout<<"Number of inversions are "<<num;
    return 0;
}