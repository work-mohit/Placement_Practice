// https://leetcode.com/problems/longest-common-prefix/

// 3 methods
/*  
    Approach ye hai ki first string ke first character ko pakad lo 
    fir baaki bachi string ke first character se match karlo
    agr sbse match ho jaati toh ans me daal do 
    wrna break krdo do aur loop khatam kr do 
    fir ans return kr do 
    
    TC: O(M*N)
    SC: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =strs.size();
        string ans= "";
        for(int i = 0; i < strs[0].size();i++){
            char ch = strs[0][i];
            
            bool match = true;
            
            for(int j = 1; j < n; j++){
                // not match codition 
                if(strs[j].size() < i ||  ch != strs[j][i]){
                    match = false;
                    break;
                }
   
            }
            if(match == false)
                break;
            else
                ans.push_back(ch);
        }
        return ans;
    }
};
///////////////////
// using sorting 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        int n =strs.size();
        string ans; 
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[n-1];
        for(int i =0; i< a.size(); i++){
            if(a[i] == b[i]){
                ans += a[i];
            }else break;
        }
        return ans;
    }
};



////////////////////////////////////

// Trie Method 

