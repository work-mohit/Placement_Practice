#include<bits/stdc++.h>
using namespace std;
// A vector that initially stores true means all are prime.
vector<bool> vec(50001,true);     // size will be what ever the number 

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
    vec[0] = vec[1]= false;  // 0 and 1 are not prime. so put false.
    // now start from i = 2 to i = n/2.
    // why i * i bcz it will not need more no.than that for n= 50 , 
    //we only need i= 7 which is 7*7= 49.
    // if vec[i] == true means a prime number.
    // then it multiples will not be a prime number 
    //for n = 50 means if 2 is prime then 4,6,8,.... 48, 50 will not be prime number.
    // and we set those values false 
    // after that we print only true values from the vector.
    for(int i = 2; i*i<= n;i++){        
        if(vec[i] == true){
            // for i = 2, ,4,6,8,10,..mark
            // for i = 3,  6,9,12,15, ..mark
            // for i = 4,  8,12,16,20,24. mark
            // for i = 5,  10,15,20,25,

            // if we see a patter that we only mark i*i th term so 
            // for below loop we can intialize j = i * i 
            // intead of 2*i
            // for(int j = 2*i; j <= n; j+= i){      
            //     vec[j] = false;
            // }
            for(int j = i*i; j <= n; j+= i){      
                vec[j] = false;
            }
        }
    }
}   
int main(){

    int n = 50;
    SieveOfEratosthenes(n);
    printArray(vec,n);
    return 0;

}