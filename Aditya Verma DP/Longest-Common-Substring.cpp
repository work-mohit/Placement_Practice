#include<iostream>
using namespace std;

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
        cout<<"print 1";
        int mx = 0;
        for(int i = 1; i<= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    mx = max(mx, dp[i][j]);
                }   
                else
                    dp[i][j] = 0;
            }
        }
        return mx;
    }
};
int main(){
    cout<<"print 1";
    Solution s;
    cout<<"print 1";
    int ans = s.longestCommonSubsequence("abcde", "abcfe");
    cout<<"hi ans is ";
    cout<<ans<<endl;
    return 0;

}
