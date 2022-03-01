// add link here


class Solution {

public:
    int findFinalValue(vector<int>& nums, int original) {
         while(original<=1000)
        {
            int cnt=0;
           for(int i=0;i<nums.size();i++)
           {
               if(nums[i]==original)
               {
                   original=2*original;
                   break;
               }
               else
               {
                   cnt++;
               }
           }
            if(cnt==nums.size())
            {
                return original;
            }
        }
        return original;
    }
    
};