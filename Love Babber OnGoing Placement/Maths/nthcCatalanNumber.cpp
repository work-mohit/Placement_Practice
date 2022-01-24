#include<bits/stdc++.h>
using namespace std;
vector<unsigned long int> catNumber(1001);

// Dynamic programming method which takes exponential time complexity
void createCatalanNumber(){
    catNumber[0] = catNumber[1] = 1;
    for(int i = 2 ; i <= 50; i++){
        unsigned long int res = 0;
        if( i & 1){
            res += catNumber[i/2]*catNumber[i/2];     
        }
        for(int j = 0; j<(i/2); j++){
            res += 2*(catNumber[j] * catNumber[i-j-1]);
        }
        catNumber[i] = res;
    }

    for(int i =0 ;i < 50; i++)
        cout<<catNumber[i]<<" ";
    
}
unsigned long int nthCatalanNumber(int n){
    return catNumber[n];
}

// Returns value of Binomial Coefficient C(n, k) 
unsigned long int binomialCoeff(unsigned int n, unsigned int k) 
{ 
	unsigned long int res = 1; 

	// Since C(n, k) = C(n, n-k) 
	if (k > n - k) 
		k = n - k; 

	// Calculate value of [n*(n-1)*---*(n-k+1)] / [k*(k-1)*---*1] 
	for (int i = 0; i < k; ++i) 
	{ 
		res *= (n - i); // 1*n , n *{n-1}, n (n-1) (n-2) 
		res /= (i + 1); // 1 2 3 4 5 
	} 

	return res; 
} 

// A Binomial coefficient based function to find nth catalan 
// number in O(n) time 
unsigned long int catalan(unsigned int n) 
{ 
	// Calculate value of 2nCn 
	unsigned long int c = binomialCoeff(2*n, n); 

	// return 2nCn/(n+1) 
	return c/(n+1); 
} 
int main(){
    createCatalanNumber();
    int t;
    cin >> t;
    vector<unsigned long int> res;
    while(t--){
        int n ;
        cin>>n;
        int r = nthCatalanNumber(n);
        res.push_back(r);
    }
    for (auto x : res)
        cout<<x<<endl;
    return 0;
}