class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>> &res, int idx){
        if(idx  == nums.size()){
            res.push_back(nums);
            return;
        }
        for(int i = idx; i < nums.size();i++){
            swap(nums[i], nums[idx]);
            solve(nums, res,idx+1);
            swap(nums[i], nums[idx]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        solve(nums,res, 0);
        return res;
    }
};

//////////////////////////////////////////////
//// Easy way of doing this 

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        solve(nums,res, 0);
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));   // ye inbuild hai STL me 
        return res; 
    }
};