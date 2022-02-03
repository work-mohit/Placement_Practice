class Solution {
public:
    int trap(vector<int>& height) {
        
        vector<int> v;
        stack<pair<int, int>> s;
        int n = height.size();
        
        vector<int> greatLeft(n,-1);   // store index to calculate width
        vector<int> smallLeft(n,-1);   // store value to calculate the length of the rectangular shaped water.
        
        // NGR
        for(int i = n-1 ; i>=0;i--){
            if(s.size()!=0){
                while(s.size() > 0 && s.top().first <= height[i]){
                    s.pop();
                }
                greatLeft[i] = s.empty() ? -1 : s.top().second;
                
            }
          s.push({height[i], i});      
        }
        
        while(!s.empty())   // clear stack for next op
            s.pop();
        
        // NSR
        for(int i = n-1 ; i>=0;i--){
            if(s.size()!=0){
                while(s.size() > 0 && s.top().first >= height[i]){
                    s.pop();
                }
                smallLeft[i] = s.empty() ? -1 : s.top().first;
       
            }
          s.push({height[i], i});      
        }
        for(auto x : smallLeft)
            cout<<x<<" ";
        cout<<endl;
        for(auto x : greatLeft)
            cout<<x<<" ";
        cout<<endl;
        int sum = 0;
        int w , h;
        for(int i = 0 ; i < n; i++){
            w = greatLeft[i] - i -1;  // -1 is the gap b/w to buildings
            if(smallLeft[i] >= 0)
                h = height[i] - smallLeft[i];
            
                
            if(w >= 0 && h >= 0)
                sum += w * h;
        }
        
        return sum;
    }
    
};



////////////////////////////////////////////////////////////////////////////////////////////

// Two Pointers Approach

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left = 0;
        int right = height.size()-1;
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                int curr = left;
                while(height[++left] < height[curr])
					ans += height[curr] - height[left];
            }
            else
            {
                int curr = right;
                while(height[--right] < height[curr])
					ans += height[curr] - height[right];
            }
        }
        return ans;
    }
};