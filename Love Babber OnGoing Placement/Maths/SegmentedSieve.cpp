#include<bits/stdc++.h>
using namespace std;
// A vector that initially stores true means all are prime.
   

void printArray(vector<bool> vec, int n){
    int count =0;
    for(int i = 0; i <= n; i++){
        if(vec[i] == true){
            count++;
            cout<<i<<" ";
        } 
    }
    cout<<endl;
    cout<<"Total: "<<count<<" prime numbers."<<endl;
}
void SieveOfEratosthenes(int n){
    vector<int> prime;
    vec[0] = vec[1]= false;  
    for(int i = 2; i*i<= n;i++){        
        if(vec[i] == true){
            prime.push_back(vec[i]);
        }
    }
    // vector<bool> vec(n /2 + 1)
    // for(int i = 0;i<vec.size();i++){
    //     int ele = vec[i];
    //     for(int j = 2*ele; j <= n; j+= ele){
            
    //     }
    // }
        
}  

void SegmentedSieve(int arr[], int limit,int n){
    
    while(){
        int low = limit;
        int limit = low + limit;
    }
    
}
int main(){

    int n = 50;
    SieveOfEratosthenes(n);
    printArray(vec,n);
    return 0;

}