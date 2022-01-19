#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int>> printPascal(int n) 
{
	vector<vector<long long int>> res;
    

    for(int i = 0; i < n; i++){
        vector<long long int> out(n+1, 1);
        for(int j = 1; j < i; j++){ 
            out[j] = res[i-1][j] + res[i-1][j-1];
              
        }
        res.push_back(out);
        
    }
    return res;
	
}
int main(){
    int n = 5;
    vector<vector<long long int> > res = printPascal(n);
    for(auto x : res){
        for (auto y :x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}