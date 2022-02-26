#include<bits/stdc++.h>
using namespace std;

#define range(i, a, n) for (int i = a; i < n; i++)
#define piv(a) printf("%d",a)
#define pis(s) printf("%s",s)
#define siv(a) scanf("%d",a)

#define vi vector<int>
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) x.begin(),x.end()
#define vb vector<bool>
#define vvl vector<vector<int> >
#defind umap unordered_map
#define mp make_pair
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