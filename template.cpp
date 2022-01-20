#include<bits/stdc++.h>
using namespace std;

#define fl(i, a, b) for (int i = a; i < b; i++)
#define piv(a) printf("%d",a)
#define pis(s) printf("%s",s)
#define siv(a) scanf("%d",a)

typedef long long int lli;
typedef vector<int> vi;

void printArray(int *arr, int size){
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
} 
void printVector(vector<int>& vec){
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
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