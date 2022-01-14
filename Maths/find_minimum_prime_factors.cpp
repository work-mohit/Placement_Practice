// for a given number n , 
// find out for of many numbers it is a minimum prime factor in the given range 1 - 10^6
// eg: 2 is the minimum factors of 4,6,8,10.... => total 500000

#include<bits/stdc++.h>
using namespace std;
#define N 1000000

int cnt[N+1];

void seive(){
    for (int i = 2; i <= N ; i++){
            cnt[i] = 1;
    }

    for(int i = 2; i*i<=N; i++){
        if(cnt[i] == 1){
            for(int j = i*i; j<= N; j+=i){
                if(cnt[j] != 0){
                    cnt[i]++;
                    cnt[j]==0;
                }
            }
        }
    }
}

int main(){
    seive();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<cnt[n]<<endl;
    }
    return 0;
}

