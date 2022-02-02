#include<bits/stdc++.h>
using namespace std;
vector<int> NSL(vector<int>& arr){
    vector<int> v;
    stack<pair<int,int>> s;    // since we need the index of the NSL
    
    for(int i = 0; i < arr.size();i++){
        if(s.size() == 0)
            v.push_back(-1);
        else if(s.size()>0 && s.top().first < arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first >= arr[i]){
            while(s.size()>0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(-1);
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i] , i});
    }
    return v;
}
vector<int> NSR(vector<int>& arr){
    vector<int> v;
    stack<pair<int,int>> s;    // since we need the index of the NSR
    
    for(int i = arr.size()-1; i>= 0; i--){
        if(s.size() == 0)
            v.push_back(arr.size());
        else if(s.size()>0 && s.top().first < arr[i])
            v.push_back(s.top().second);
        else if(s.size()>0 && s.top().first >= arr[i]){
            while(s.size()>0 && s.top().first >= arr[i]){
                s.pop();
            }
            if(s.size() == 0)
                v.push_back(arr.size());
            else
                v.push_back(s.top().second);
        }
        s.push({arr[i] , i});
    }
    reverse(v.begin(),v.end());
    return v;
}
int maxArea(vector<int>& arr){
    vector<int> left = NSL(arr);
    vector<int> right = NSR(arr);
    int area = 1;
    int maxarea= -1;  // since area can't be in minus so it's always less then any value we can also Use INT MIN
    for(int i = 0 ; i < arr.size();i++){
        int width = right[i] - left[i] -1;
        area = arr[i]* width;
        maxarea = max(maxarea, area); 
    }
    return maxarea;
}
int main(){
    vector<int> arr ={6,2,5,4,5,1,6};
    int area = maxArea(arr);
    cout<<"Maximum area of histogram is "<<area;
    
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// Same Approach - Better Code 
class Solution {
private:
    int maxArea(vector<int>& arr){
        int n = arr.size();
        vector<int> left(n), right(n);
        //NSL
        stack<pair<int,int>> s;
        

        for (int i = 0; i < arr.size(); i++) {
            if (s.size()!= 0) {
                while (s.size() > 0 && s.top().first >= arr[i]) {
                    s.pop();
                }
            }
            left[i] = s.empty() ? -1 : s.top().second;
            s.push({arr[i],i}); 

        }

        while(!s.empty())s.pop();
        // NSR
        for (int i = arr.size()-1; i >= 0; i--) {
            if (s.size()!= 0) {
                while (s.size() > 0 && s.top().first >= arr[i]) {
                    s.pop();
                }
            }
            right[i] = s.empty() ? n : s.top().second;
            s.push({arr[i], i}); 
        }
        
       
        int maxarea= -1; 
        for(int i = 0 ; i < arr.size();i++){
            maxarea = max(maxarea, (arr[i] * (right[i] - left[i] -1))); 
        }
        return maxarea;
    }
     
    
public:
    int largestRectangleArea(vector<int>& heights) {
        return maxArea(heights);
    }
};
