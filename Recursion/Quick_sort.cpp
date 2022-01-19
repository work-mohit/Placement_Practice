#include<bits/stdc++.h>
using namespace std;

void printArray(int arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int partition(int *arr , int start , int end){
    int pivot;
    int ele = arr[start];
    int cnt = 0;
    for(int i = start+1; i <= end; i++){
        if(arr[i]<ele)
            cnt++;
    }
    pivot = start + cnt;
    swap(arr[pivot], arr[start]);
    int i = start;
    int j = end;
    while(i <  pivot && j > pivot){
        while(arr[i] < arr[pivot])
            i++;

        while(arr[j] > arr[pivot])
            j--;

        if(i <  pivot && j > pivot){
            swap(arr[i] , arr[j]);
            i++;
            j--;
        }       
    }
    return pivot;

}
void quickSort(int *arr, int start , int end){
    if (start >= end)
        return;
    
    int p = partition(arr, start, end);
    quickSort(arr, start , p-1);
    quickSort(arr, p+1, end);

}
int main(){
    int arr[10] = {2,3,1,5,68,6,4,77,61,34};
    int n = 10;
        
    quickSort(arr, 0, n-1);
    printArray(arr,n);
    return 0;
}