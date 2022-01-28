#include<iostream>
using namespace std;
bool isPrime(int n){
    if(n <=1)
        return false;
    if(n==2 || n==3)
        return true;
    for(int i = 1; i < n-2;i++){
        if(6*i == n-1 || 6*i == n+1)
            return true;
    }
    return false;
}
int main(){
    int n = 997;
    if(isPrime(n))
        cout<<"is prime";
    else 
        cout<<"not prime";
    return 0;
}