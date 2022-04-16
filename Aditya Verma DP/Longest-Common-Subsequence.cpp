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

class Solution {
public:
    int dp[1001][1001]; 
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        for(int i = 0; i<= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i<= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};