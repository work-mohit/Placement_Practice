#include<bits/stdc++.h>
using namespace std;
#define N 86028121    // optimal no that we have found.

bool vec[N + 1]; 
vector<int> prime;

void createSeive(){
    for (int i = 2; i <= N ; i++){
        vec[i] = true;
    }
    
      
    for(int i = 2; i*i <= N;i++){        
        if(vec[i] == true){
            for(int j = i*i; j<=N; j+=i){      
                vec[j] = false;
            }
        }
    }
   

    for(int i = 2;i<=N; i++){
        if(vec[i] == true){
            prime.push_back(i);
            
        }
    }   
    
}   
int main(){
    createSeive();
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<prime[n-1]<<endl;
    }
    
    return 0;
    

}