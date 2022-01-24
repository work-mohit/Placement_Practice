// You are given one integer number n. Find three distinct integers a,b,c such that 2≤a,b,c and a⋅b⋅c=n or say that it is impossible to do it.

// If there are several answers, you can print any.

// You have to answer t independent test cases.

// Inputs : 
// 5
// 64
// 32
// 97
// 2
// 12345

// Outputs 
// YES
// 2 4 8 
// NO
// NO
// NO
// YES
// 3 5 823 

#include<bits/stdc++.h>
using namespace std;
void findFactors(int n){
    int a=n,b=n,c=n; // if we get prime then this is useful bcz for prime 1 or n only factors
    for (int i = 2;i*i<=n;i++){
        if(n % i == 0){           // simple method to find smallest factor
            a = i;
            break;  // break as soon as we find 
        }
    }

    n = n / a;  // since we need distinct a* b* c = n => b*c = n/a
    // now loop for next factor j can be 2 or a+1
    // check later is there any effect with j = 2 of j = a+1
    for(int j = a+1; j*j <= n; j++){     
        if(n % j == 0 && j != a){       // if j is a factor and j != a
            b = j ;
            break; // break
        }
    }
    c = n / b; // c = n/(a*b) , since we already done n = n/a now do n = n/b.
    // a ,b & c are distinct and c >= 2 ,a & b can't bcz we starting them form 2.
    if ( a != b && b != c && c >= 2) 
        cout<<a<<" "<<b<<" "<<c<<endl;
    else 
        cout<<"Not Possible."<<endl;
}
int main(){
    int t; 
    cin>>t;
    vector<int> vec;
    while(t--){
        int n;
        cin>>n;
        vec.push_back(n);    
    }
    for(int x : vec)
        findFactors(x);
    return 0;
}