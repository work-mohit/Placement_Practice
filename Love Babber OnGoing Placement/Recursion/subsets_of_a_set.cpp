// https://leetcode.com/problems/subsets/
// Problem Solution
class Solution {
private:
    void solve(vector<vector<int>>& ans, vector<int>& nums,vector<int> out, int index){
        // base condition
        if(index >= nums.size()){
            ans.push_back(out);
            return ;
        }
            
        // exclude
        solve(ans, nums,out, index+1);
        // include
        int element = nums[index];
        out.push_back(element);
        solve(ans, nums, out, index+1);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> out;
        int index = 0;
        solve(ans, nums, out, index);
        return ans;
    }
};