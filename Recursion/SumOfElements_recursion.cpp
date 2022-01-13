#include<bits/stdc++.h>
using namespace std;
 
int SumOfElements(int arr[], int size, int sum){
    if(size == 0)
        return 0;
    if(size == 1);
        return arr[0];
    
    sum = arr[0] + SumOfElements(arr+1 , size-1 , sum);

    return sum ;


}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size =(int) sizeof(arr)/sizeof(arr[0]);

    int ans = SumOfElements(arr, size , 0);
    
    printf("The sum of the elements is %d", ans);
    return 0;
} 