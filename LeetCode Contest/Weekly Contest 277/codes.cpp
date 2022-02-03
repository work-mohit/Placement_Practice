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


// 2149. Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> s1;
        queue<int> s2;
        for(int x : nums){
            if(x > 0)
                s1.push(x);
            else
                s2.push(x);
        }
        for(int i= 0; i < nums.size();i++){
            if(i & 1){
                nums[i] = s2.front();
                s2.pop();
            }
            else{
                nums[i] = s1.front();
                s1.pop();
            }
        }
     return nums ;
                
                
            
    }
};


// 2150. Find All Lonely Numbers in the Array

class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> umap;
        vector<int> v;
        for(int x: nums){
            umap[x]++;
        }
        for(int x : nums){
            if(!(umap[x-1] > 0 || umap[x+1]> 0 || umap[x] > 1))
                v.push_back(x);
        }
        return v;
    }
};