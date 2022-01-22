#include<bits/stdc++.h>
using namespace std;

#define fl(i, a, b) for (int i = a; i < b; i++)
#define piv(a) printf("%d",a)
#define pis(s) printf("%s",s)
#define siv(a) scanf("%d",a)

typedef long long int lli;
// typedef vector<int> vi;
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


void moveNegative(vector<int>& vec){
    int j = 0;
    for(int i = 0; i< vec.size(); i++){
        if( vec[i] < 0 && i != j){
            swap(vec[i], vec[j]);
            j++;
        }       
    }
}
int main(){
    vector<int> vec  ={3,4,5,-3, -4, -8,10,0};
    moveNegative(vec);
    printVector(vec);
    return 0;
}