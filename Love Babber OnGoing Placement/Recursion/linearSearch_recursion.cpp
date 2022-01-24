#include<bits/stdc++.h>
using namespace std;
 
int linearSearch(int arr[], int size,int key,int index){
    if (index == size)
        return false;

    if(arr[index] == key)
        return index;
    else{
        return linearSearch(arr, size, key, index+1);
    }
    

}

int main(){
    int arr[] = {2,3,4,7,6,7,8,9};
    int size =(int) sizeof(arr)/sizeof(arr[0]);
    int key = 4;
    int index = linearSearch(arr, size, key, 0);
    if(index == -1)
        printf("Element not found.");
    else
        printf("The element %d is in the %d index.", arr[index] , index);

    return 0;
} 