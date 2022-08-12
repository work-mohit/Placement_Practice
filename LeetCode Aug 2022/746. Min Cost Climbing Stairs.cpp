// ye rha dp 
// https://leetcode.com/problems/min-cost-climbing-stairs/


/* 
Approach : 
    -Initially we have two either we can start from the the index 0 or by index 1.
    -now from a cell i can go either 1 index away or 2 index forward.
    -which index i will is depend on the which index have minimum value.

*/


class Solution {
public:
    int helper(vector<int>& cost , int n, int i,vector<int>& dp){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = min(helper(cost, n, i+1,dp), helper(cost, n , i+2,dp)) + cost[i];     
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n , -1);
        int s = helper(cost,cost.size(), 0, dp);
        int y = helper(cost, cost.size(), 1, dp);
        return min(s, y);
    }
};

// optimal ans that i found on discuss

int minCostClimbingStairs(vector<int>& cost) {
	int prev = cost[0]; // base case 1
	int curr = cost[1]; // base case 2

	for (int i = 2; i < cost.size(); i++) {
		int tmp = curr;
		curr = min(prev, curr) + cost[i]; // calculates the min cost using step i
		prev = tmp; // prev is moved forward one step
	}
	return min(curr, prev); // min of the final 2 steps, don't need to use last step
}