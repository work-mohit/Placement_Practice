// my approach
// with space 
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> umap;
        
        for(auto &x: nums){
            umap[x]++;
        }
        int res = 0;
        int i = 1;
        while(1){
            if(!umap[i]){
                res = i;
                break;
            }
                
            i++;
        }
        return res;
    }
};

// optimized time
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(i+1==nums[i]) continue;
            int x = nums[i];
            while(x>=1 && x<=nums.size() && x!=nums[x-1]){
                swap(x, nums[x-1]);
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(i+1!=nums[i])    return i+1;
        }
        return nums.size()+1;
    }
};

// best approach that i learned 

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i< n; i++){
            if(nums[i] <= 0)
                nums[i] = n+1;
        }
        
        for(int i = 0; i < n; i++){
            if(abs(nums[i]) <= n && nums[abs(nums[i])-1] > 0)
                nums[abs(nums[i])-1] *=  -1;
        }
        
        for(int i =0; i< n;i++){
            if(nums[i] > 0)
                return i+1;
        }
        return n+1; 
    }
};
