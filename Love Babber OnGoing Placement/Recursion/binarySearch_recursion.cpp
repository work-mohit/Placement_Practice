#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int low , int high){
    for (int i= low ; i < high; i++)
        cout<< arr[i]<< " ";
    cout<<endl;
}
int binarySearch(int arr[], int low , int high, int key){
    printArray(arr,low,high);
    if (low > high)
        return -1;
    if (arr[low] == key)
        return low;
    if (arr[high] == key)
        return high;
    
    int mid = low + (high - low)/2;
    cout<<"The mid is " << arr[mid]<<endl<<endl;
    if(arr[mid]== key)
        return mid;
    else if(key < arr[mid])
        return binarySearch(arr,low , mid -1, key);
    else   
        return binarySearch(arr, mid + 1, high, key);

}

int main(){
    int arr[] = {2,3,4,5,6,7,8,9}; // array must be sorted already
    int size =(int) sizeof(arr)/sizeof(arr[0]); // calcualte the size of the array

    int key = 9; // element to be found
    int index = binarySearch(arr,0, size, key);

    if(index == -1)
        cout<<"Element not found."<<endl;
    else
        cout<<"The element "<< arr[index] << " is in the " << index<<" index."<< endl;

    return 0;
} 