// Naive approach -: Traverse all the elements with two for loops O(N*N)

// Better approach -: since matrix is ordered ( it's like a sorted array just aligned into a matrix)
//                 check if target is in b/w first and last element of the row first <= ele <= last

// Best Approach : don't considered it as a matrix  just take care of the indices

#include<bits/stdc++.h>
using namespace std;

#define fl(i, a, b) for (int i = a; i < b; i++)
#define piv(a) printf("%d",a)
#define ps(s) printf("%s",s)
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

//  Main Function
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    pair<int, int > ans;
    int i = 0;
    int temp = 0;
    // idea is that we put every no at their correct location 
    // 4 1 2 3 5 for this at i = 0 temp = 3(4-1) => swap(arr[0],arr[3]) now at arr[3] we have 4 which is the correct position.
    while(i < n){
         temp = arr[i]-1;
         if(arr[i] != arr[temp]){
             swap(arr[i],arr[temp]);
         }
        else
            i++;
     }
    for(int i = 0; i < n; i++){
        if(arr[i] != i+1){
            ans.first = i+1;
            ans.second = arr[i];
        }     
    }
    
    return ans;
}
int main(){
    vector<vector<int>> matrix ={ {3,4,5},
                                  {4,6,8},
                                  {8,0,2} };
    int element = 1;
    pair<int,int> index = searchElement(matrix, element);
    ps("The index of the element is ");
    cout<<"["<<index.first<<","<<index.second<<"]";
    return 0;
}