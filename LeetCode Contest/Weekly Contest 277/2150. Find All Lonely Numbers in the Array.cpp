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