#include<bits/stdc++.h>
using namespace std;
vector<vector<long long int>> printPascal(int n) 
{
	vector<vector<long long int>> res;
    vector<long long int> out;
    cout<<"hi";

    
    
    cout<<"helo";
    if(n <= 2)
        return res;
    cout<<"hi";
    for(int i = 2; i < n; i++){
        out.push_back(1);
        cout<<"hi";
        for(int j = 2; j < n-1; j++){ 
            int sum = res[i-1][j] + res[i-1][j-1];
            out.push_back(sum);
            
        }
        out.push_back(1);
        res.push_back(out);
        out.clear();
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