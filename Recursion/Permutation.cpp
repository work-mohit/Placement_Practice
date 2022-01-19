// https://leetcode.com/problems/permutations/

class Solution {
private:
    void solve(vector<vector<int>>& res, vector<int>& nums, int index){
        if(index >= nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++){    // for each letter     for first call 
            swap(nums[index], nums[i]);            // first we swap and   abc => swap(0,0) => swap (a,a)
            solve(res, nums, index+1);              // do recursion 
            swap(nums[index] , nums[i]);               // swap back to 
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> res;
        solve(res, nums,0);
        return res;
    }
};