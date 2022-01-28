// https://leetcode.com/problems/find-the-duplicate-number/

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

int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int temp = 0;
    while(i < n){
        temp = nums[i] - 1;
        if (nums[i] != nums[temp]){
            swap(nums[i] , nums[temp]);
        }
        else
            i++;
    }
    for(int i = 0;i<n; i++){
        if(nums[i] != i+1)
            return nums[i];
    }
    return -1;
}

int main(){
    vector<int> v = {1,2,3,4,5,5};
    int index = findDuplicate(v);
    cout<<"The duplicate number is the "<<index<<endl;

    return 0;
}