#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[],int size){
    for (int i= 0 ; i < size; i++)
        cout<< arr[i]<< " ";
    cout<<endl;
}

void bubbleSort(int *arr, int size){
    if (size == 0 || size == 1)
        return;
    int flag= 0;
    for(int i = 1; i < size; i++){
        if(arr[i-1] > arr[i]){
            swap(arr[i-1], arr[i]);
            flag = 1;
        }
    }
    if(flag == 0){
        cout<<"Already Sorted!"<<endl;
        return;
    }
    return bubbleSort(arr, size-1); 
    
}
int main(){
    int arr[] = {2,5, 6, 85, 90}; 

    int size =(int) sizeof(arr)/sizeof(arr[0]); // calcualte the size of the array
    
    cout<<"Array before sorting."<<endl;
    printArray(arr,size); 

    bubbleSort(arr, size);

    cout<<"Array after sorting."<<endl; 
    printArray(arr,size); 
    
    return 0;
    

}