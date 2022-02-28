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