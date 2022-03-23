#include<bits/stdc++.h> 
using namespace std;

void Heapify(int arr[], int i, int n){
    int largest = i;
    int leftchild = 2*i + 1;
    int rightchild = 2*i + 2;

    if(leftchild < n && arr[leftchild] > arr[i]){
        largest = leftchild;
    }
    if(rightchild < n && arr[rightchild] > arr[largest]){
        largest = rightchild;
    }
    if(largest != i){
        swap(arr[i], arr[largest]);
        Heapify(arr, largest, n);
    }
}


void convertMaxHeap(int arr[], int n){
    for(int i = n/2 -1; i>= 0; i--){
        Heapify(arr, i , n);
    }

}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", arr[i]);
}

int main()
{
    // array representing Min Heap
    int arr[10] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Min Heap array : ");
    printArray(arr, n);
 
    convertMaxHeap(arr, n);
 
    printf("\nMax Heap array : ");
    printArray(arr, n);
 
    return 0;
}