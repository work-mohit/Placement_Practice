#include<bits/stdc++.h>
using namespace std;

#define fl(i, a, b) for (int i = a; i < b; i++)
#define piv(a) printf("%d",a)
#define pis(s) printf("%s",s)
#define siv(a) scanf("%d",a)

typedef long long int lli;


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
int mininumJumps(vector<int>& vec){
    int n = vec.size();
    int jumps[n] = {0};
    int cnt = 0;
    if(n == 1)
        return cnt;
    for(int i = 0; i< n ; i++){
        
    }
}

int main(){
    vector<int> vec = {3,4,5,1,2,3,7,4,0,0,2,4,5};
    int jumps = mininumJumps(vec);
    pi(jumps);
    return 0;
}