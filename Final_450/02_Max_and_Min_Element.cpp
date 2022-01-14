// https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include<bits/stdc++.h>
using namespace std;
void minAndMax(int arr[], int n){
    int min = INT_MAX, max = INT_MIN;
    for(int i = 0; i < n ; i++){
        if(arr[i] > max)
            max = arr[i];
        if(arr[i] < min)
            min = arr[i];
    }
    cout<<min<<" "<<max<<endl;
}
int main(){
    int arr[] = {1, 5, 9, 6,86,92,4,6};
     
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Min and Max :"<<endl;
    minAndMax(arr, n);
    return 0;
}