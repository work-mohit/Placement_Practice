#include<bits/stdc++.h>
using namespace std;
 
bool isSorted(int arr[], int size){
    if(size == 0 || size == 1)
        return true;
    
    if (arr[0] > arr[1])
        return false;
    else
        return isSorted(arr+1, size -1);
    


}

int main(){
    int arr[] = {2,3,4,7,6,7,8,9};
    int size =(int) sizeof(arr)/sizeof(arr[0]);

    if(isSorted(arr, size)){
        printf("Sorted");
    }
    else 
        printf("Not Sorted");

    return 0;
} 