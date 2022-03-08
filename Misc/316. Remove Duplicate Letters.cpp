//https://leetcode.com/problems/remove-duplicate-letters/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256,0);
        vector<bool> vis(256,false);
        string ans ="";
        
        for(auto ch : s)  dict[ch]++;
        
        for(auto c : s) {
            dict[c]--;
            /** to filter the previously visited elements **/
            if(vis[c])  continue;
            
            while(!ans.empty() && c < ans.back() && dict[ans.back()]) {
                vis[ans.back()] = false;
                ans.pop_back();
            }
            ans += c;
            vis[c] = true;
        }
        return ans;
    }
};