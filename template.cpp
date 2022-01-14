#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n ;
        cin>>n;
        solve(n);
    }
    return 0;
}