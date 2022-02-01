// Nearest Greater to Right
#include<bits/stdc++.h>
using namespace std;
vector<int> NGR(vector<int>& nums){
    vector<int> v;
    stack<int> s;

    for(int i = nums.size()-1; i>= 0; i--){
        if(s.size()== 0)
            v.push_back(-1);
        else if(s.size() > 0 && s.top() > nums[i])
            v.push_back(s.top());
        else if(s.size() > 0 && s.top() <= nums[i]){
            while(s.size() > 0 && s.top() <= nums[i])
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


// from gfg
vector<int> printNGE(vector<int>& arr)
{
    stack<int> s;
    vector<int> res(arr.size());
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        
        // /* if stack is not empty, then
        // pop an element from stack.
        // If the popped element is smaller
        // than next, then
        // a) print the pair
        // b) keep popping while elements are
        // smaller and stack is not empty */
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
    vector<int> v= {1,8,10,4,5};
    cout<<"Vector is :"<<endl;
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;
    cout<<"1 "<<endl;
    vector<int> res = printNGE(v);
    
    cout<<"Nearest Greater to right are :"<<endl;
    for(auto x : res)
        cout<<x<<" ";
    return 0;
}