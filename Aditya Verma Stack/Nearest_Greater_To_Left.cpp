#include<bits/stdc++.h>
using namespace std;
vector<int> NGL(vector<int>& nums){
    vector<int> v;
    stack<int> s;

    for(int i = 0; i< nums.size(); i++){
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
    return v;
}
int main(){
    vector<int> v= {1,8,4,5,2};
    cout<<"Vector is :"<<endl;
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;
    vector<int> res = NGL(v);
    cout<<"Nearest Greater to left are :"<<endl;
    for(auto x : res)
        cout<<x<<" ";
    return 0;
}