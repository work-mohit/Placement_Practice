// Nearest Smaller to left
#include<bits/stdc++.h>
using namespace std;

vector<int> NSR(vector<int>& nums){
    vector<int> v;
    stack<int> s;

    for(int i = nums.size()-1; i >= 0; i--){
        if(s.size()==0)
            v.push_back(-1);
        else if(s.size() > 0 && s.top() < nums[i])
            v.push_back(s.top());
        else if(s.size() > 0 && s.top() >= nums[i]){
            while(s.size() > 0 && s.top() >= nums[i])
                s.pop();
            if(s.size()==0)
                v.push_back(-1);
            else
                v.push_back(s.top());
        }
        s.push(nums[i]);
    }
    reverse(v.begin(), v.end());
    return v;
}
// different code 

vector<int> printNSL(vector<int>& arr)
{
    stack<int> s;
    vector<int> res(arr.size());  // declare size so that you can access element with indexing 
    
    for (int i = arr.size()-1; i >= 0; i--) {
        if (s.size()!= 0) {
            while (s.size() > 0 && s.top() <= arr[i]) {
                s.pop();
            }
        }
        res[i] = s.empty() ? -1 : s.top();
        s.push(arr[i]); 
         
    }
   
    return res;
}

int main(){
    vector<int> v= {1,3,2,4};
    cout<<"Vector is :"<<endl;
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;
    vector<int> res = NSR(v);
    cout<<"Nearest Smallest to Right are :"<<endl;
    for(auto x : res)
        cout<<x<<" ";
    return 0;
}