// https://leetcode.com/problems/sort-colors/ 
// Method 1: Sorting the nums vector (PS. total scam)
// Time complexity - O(n log n)
// class Solution {
// public:
//     void sort012(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//     }
// };

// Method 2: keep a count of 0's 1's and 2's
// Time complexity - O(2N)

// class Solution {
// public:
//     void sort012(vector<int>& nums) {
//         int count0 = 0;
//         int count1 = 0; 
//         int count2  = 0;
//         for(int i =0; i< nums.size(); i++){
//             if(nums[i] == 0){
//                 count0++;
//             }else if (nums[i] == 1){
//                 count1++;
//             }else if (nums[i] ==2 ){
//                 count2++;
//             }
            
//          }
//         for(int i =0; i< count0; i++){
//             nums[i] =0;
//         }
//         for(int i =count0; i< (count1 + count0); i++){
//             nums[i] =1;
//         }
//         for(int i =(count1 + count0); i< nums.size(); i++){
//             nums[i] =2;
//         }
        
//     }
// };
// Method 3: using 3 pointers
// Time complexity - O(N)


void sort012(vector<int>& nums) {
    int front = 0;
    int mid = 0;
    int high = nums.size()-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[front++], nums[mid++]);
        }  
        else if(nums[mid] == 1){
            mid++;
        }
        else{
            swap(nums[mid],nums[high--]);
        }
    }
    
}