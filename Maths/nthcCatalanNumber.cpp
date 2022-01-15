#include<bits/stdc++.h>
using namespace std;

// Dynamic programming method which takes exponential time complexity
int nthCatalanNumber(int n){
    vector<long long int> catNumber(1001);
    catNumber[0] = catNumber[1] = 1;
    for(int i = 2 ; i <= n; i++){
        long long int res = 0;
        if( i & 1){
            res += catNumber[i/2]*catNumber[i/2];     
        }
        for(int j = 0; j<(i/2); j++){
            res += 2*(catNumber[j] * catNumber[i-j-1]);
        }
        catNumber[i] = res;
    }
    for(int i =0 ;i < n; i++)
        cout<<catNumber[i]<<" ";
    return catNumber[n];
}
int main(){
    int t;
    cin >> t;
    vector<long long int> res;
    while(t--){
        int n ;
        cin>>n;
        int r = nthCatalanNumber(n);
        res.push_back(r);
    }
    for (int x : res)
        cout<<x<<endl;
    return 0;
}