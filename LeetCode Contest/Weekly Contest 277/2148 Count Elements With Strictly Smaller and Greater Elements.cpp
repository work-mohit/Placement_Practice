//  2148 Count Elements With Strictly Smaller and Greater Elements
class Solution {
public:
    int countElements(vector<int>& nums) {
         if(nums.size()< 2)
             return 0;
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int mi = nums[0];
        int mx = nums[n-1];
        for(int x : nums)
            if( x > mi && x < mx)
                cnt++;
        return cnt;
    }
};

// copied but faster 

class Solution {
public:
    int countElements(vector<int>& nums) {
    
        int maxi = nums[0], maxiFreq = 0;
        int mini = nums[0], miniFreq = 0;
        
        for (auto i : nums)
        {
            maxi = max(maxi, i);
            mini = min(mini, i);
        }
        
        for (auto i : nums)
            if (i == maxi)
                maxiFreq++;
            else if (i == mini)
                miniFreq++;
        
        int res = nums.size() - (maxiFreq + miniFreq);
        
        return res;
    }
};





