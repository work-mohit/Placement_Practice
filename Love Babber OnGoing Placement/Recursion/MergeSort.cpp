#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void merge(int *arr, int low , int high){
    int mid = (low + high)/2;
    int len1 = mid-low+1;
    int len2 = high-mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    // copy values

    int mainIdx = low;
    for ( int i = 0; i<len1; i++){
        arr1[i] = arr[mainIdx++];
    }
    mainIdx  = mid+1;
    for (int i = 0; i < len2;i++){
        arr2[i] = arr[mainIdx++];
    }

    int idx1 = 0;
    int idx2 = 0;

    mainIdx = low;

    while(idx1 < len1 && idx2 < len2){
        if(arr1[idx1]< arr2[idx2]){
            arr[mainIdx++] = arr1[idx1++];
        }else{
            arr[mainIdx++] = arr2[idx2++];
        }  
    }

    while(idx1<len1){
        arr[mainIdx++] = arr1[idx1++];
    }
    while(idx1 < len2){
        arr[mainIdx++] = arr2[idx2++];
    }
    delete arr1;
    delete arr2;
}
void mergeSort(int *arr, int low , int high){

    if (low >= high)
        return;

    int mid= low + (high - low)/ 2;
    mergeSort(arr,low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, high);

}

int main(){
    int arr[10] = {2,5,67,4,5,73,56,39,35,3};
    int n = 10;
    printArray(arr,n);
    mergeSort(arr, 0, n-1);
    cout<<"Values After Sorting:"<<endl;
    printArray(arr,n);
    return 0;
}