#include<bits/stdc++.h>
using namespace std;

long long int calculatePower(int n , int p){
    cout<<"n = "<<n<<"p ="<<p<<endl;
    if (p == 0)
        return 1;
    if(p == 1)
        return n;

    if(p % 2 == 0){
        
        return calculatePower(n, p/2) * calculatePower(n , p/2);
    }   
    else 
        return n * calculatePower(n, p/2) * calculatePower(n , p/2);
   
}
int main(){
    int n , p ;
    cin>>n >> p;
    long long int res = calculatePower(n, p);
    cout<<res;
    return 0;
}