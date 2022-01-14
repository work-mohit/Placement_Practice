// https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/

#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int size)
{
   for (int i = 0; i < size; i++)
   cout << arr[i] << " ";
 
   cout << endl;
}
void reversedArray(int *arr, int size){
    int low = 0;
    int high = size-1;
    if (size == 1)
        return;
    while(low<=high){
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
}
int main(){
    int arr[] = {1, 5, 9, 6,86,92,4,6};
     
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Before:"<<endl;
    printArray(arr, n);

    reversedArray(arr,n);

    cout<<"After:"<<endl;
    printArray(arr, n);
    return 0;
}