#include<bits/stdc++.h>
using namespace std;

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void sortArray(int *arr , int n){

    // use count sort logic
    // 0 -> __  if occurs then
    // 1 -> __   increase
    // 2 -> __
    vector<int> vec(1000000,0);

    for(int i =0; i<n; i++){
        vec[arr[i]]++;
          
    }
    int index=0;
    for (int i=0;i<n;i++){
        while (vec[i] != 0){
            arr[index++]=i;
            vec[i]--;
            
        }
    }
}
void sort012(int *arr, int n){
    // Three pointer technique
    
    int low , mid , high;
    low = 0;
    mid = 0;
    high = n-1;
    
    while(mid <= high){
        if(a[mid] == 0){
            swap(a[low],a[mid]);
            low++;
            mid++;
        }
        else if(a[mid]== 1)
            mid++;
            
        else{
            swap(a[mid], a[high]);
            high--;
        }
    }
}
int main(){
    int arr[10]={1,2,1,2,2,0,0,2,1,0};
    int n = 10;
    cout<<"Before Sorting:";
    printArray(arr,n);
    sortArray(arr, n);
    cout<<"After Sorting:";
    printArray(arr, n);
    return 0;
}