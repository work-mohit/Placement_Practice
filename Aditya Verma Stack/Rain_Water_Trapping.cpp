// DP Solution

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxL[n], maxR[n];
        
        maxL[0] = height[0];
        
        for(int i = 1; i < n ; i++){
            maxL[i] = max(maxL[i-1], height[i]);
        }
        
        maxR[n-1] = height[n-1];
        
        for(int i = n-2; i>=0 ; i--){
            maxR[i] = max(maxR[i+1], height[i]);
        }
         
        int sum = 0;
        for(int i =0 ; i< n; i++){
            sum = sum + (min(maxL[i], maxR[i]) - height[i]);
            
        }
        return sum;
    }
    
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Using Stacks'


class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> s;
        int n = height.size();
        for(int i = 0; i< n; i++){
            if(!s.empty() &&height[i] > height[s.top()]){
                int top = s.top();
                s.pop();

                width = i - s.top() -1;
                height = min(height[i], height[s.top()]) - height[top];
                res += widht * height;
            }
            s.push(i);
        }
        return res;
    }
};




////////////////////////////////////////////////////////////////////////////////////////////

// Two Pointers Approach

class Solution {
public:
    int trap(vector<int>& height) {
        int i = 0 , j = height.size()-1, maxLeft = 0 , maxRight = 0, water = 0;
        
        while(i < j){
            if(height[i] <= height[j]){
                maxLeft = max(maxLeft, height[i]);
                water += maxLeft - height[i];
                i++;
            }else{
                maxRight = max(maxRight, height[j]);
                water += maxRight - height[j];
                j--;
            }
        }
        return water; 
    }
};