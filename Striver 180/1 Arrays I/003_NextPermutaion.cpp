// https://leetcode.com/problems/next-permutation/

// State forward solution
// void nextPermutation(vector<int>& nums) {
//     next_permutation(begin(nums), end(nums));
// }


void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    if( n < 2)
        return;
    
    int back = n-1;
    
    int index = -1;
    for(int i = back; i >= 1; i--){
        if(nums[i] > nums[i-1]){
            index = i-1;
            break;
        }
    }
    if(index == -1){
        reverse(nums.begin(), nums.end());
        return;
    }
    for(int i = back;i>index; i--){
        if(nums[i] > nums[index]){
            swap(nums[index], nums[i]);
            reverse(nums.begin()+index+1, nums.end());
            break;
        }

    }
}