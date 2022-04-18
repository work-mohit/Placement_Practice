// recursive approach 
// will give TLE in leetcode 
class Solution {
public:
    int lcsUtil(string text1 , string text2, int n , int m){
        if(n == 0 || m == 0)
            return 0;
        
        if(text1[n-1] == text2[m-1])
            return 1 + lcsUtil(text1, text2, n-1, m-1);
        else
            return max(lcsUtil(text1, text2, n, m-1), lcsUtil(text1, text2, n-1, m));
    }
    int longestCommonSubsequence(string text1, string text2) {
        return lcsUtil(text1, text2, text1.size(),text2.size());
    }
};

//// bottom up recusion + memoization
class Solution {
public:
    int dp[1001][1001];
    int lcsUtil(string text1 , string text2, int n , int m){
        if(n == 0 || m == 0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        
        if(text1[n-1] == text2[m-1])
            return dp[n][m] = 1 + lcsUtil(text1, text2, n-1, m-1);
        else
            return dp[n][m] = max(lcsUtil(text1, text2, n, m-1), lcsUtil(text1, text2, n-1, m));
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return lcsUtil(text1, text2, text1.size(),text2.size());
    }
};
///////// top down dp 





//// There is one more approach that is space utilized 
// which solve the problem in O(2*N) 


