
// You are given a three integers 'X', 'N', and 'M'. Your task is to find ('X' ^ 'N') % 'M'.
//  A ^ B is defined as A raised to power B and A % C is the remainder when A is divided by C.
// https://www.codingninjas.com/codestudio/problems/modular-exponentiation_1082146?utm_source=youtube&utm_medium=affiliate&utm_campaign=love_babbar_7&leftPanelTab=
// 2 
// 3 1 2
// 4 3 10

#include<bits/stdc++.h>
using namespace std;
//  (n^p) % m calculate it.
int fastExpo(long long n, int p,int m){  // took n = long long or typecast it later so that it dont overflow
    long long res = 1;
    while(p > 0){     
        if(p & 1){     // check odd
            res = (res * n) % m;
        }
        n = (n * n )% m;
        p = p>>1;    // dividing by 2 it's more fast than dividing operator.

    }
    return res;
}

int main(){
    int t;
    cin >> t;
    int n , p , m;
    vector<int> res;
    while(t--){
        cin>>n>>p>>m;
        int x = fastExpo(n, p,m);
        res.push_back(x);
    }
    for (int x : res)
        cout<<x<<endl;
    return 0;
}