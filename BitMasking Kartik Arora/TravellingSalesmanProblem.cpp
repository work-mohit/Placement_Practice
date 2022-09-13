#include<bits/stdc++.h>
int helper(vector<vector<int>>& distance,vector<vector<int>>& dp, int i , int mask,  int& n){   
    // base case jb ek ek krke sb bhar jaaega toh at the end the mask 0 ho jaaega
    // at that time jis jagah hai wha se starting element tk ki distance de denge
    
    if (mask == 0)
        return distance[i][0];

    if (dp[i][mask] != -1)
        return dp[i][mask];

    int ans = INT_MAX;
    for (int j = 0; j < n; j++) {
        if (mask & (1 << j))
            ans = min(ans, distance[i][j] + helper(distance, dp, j, mask ^ (1 << j), n));
    }
    return dp[i][mask] = ans;
}

int shortestRoute(vector<vector<int>> &distance)
{
	int n = distance.size();
    if(n == 1)
        return distance[0][0];
    vector<vector<int>> dp(n, vector<int> (1<<n, -1));
    
    return helper(distance, dp, 0,(1<<n)-2, n);
}
