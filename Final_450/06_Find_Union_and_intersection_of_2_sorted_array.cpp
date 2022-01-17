
#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int doUnion(int *a, int n, int *b, int m)  {
    int i =0 ;
    int j = 0;
    int count =0;
    while( i < n && j < m){
        if (a[i++] == b[j++])
            count++;
        else if(b[j] > a[i]){
            count++;
            i++;
        }
        else{
            j++;
            count++;
        }    
    }
    while(i < n){
        count++;
        i++;
    }
    while(j < m){
        count++;
        j++;
    }
    return count;
}

int main(){
    int arr1[7]={1,2,3,5,6,7,8};
    int arr2[5]={3,4,5,7,8};
    int n = 7;
    int m = 5;
    
    cout<<doUnion(arr1,n , arr2,m);
    
    return 0;
}