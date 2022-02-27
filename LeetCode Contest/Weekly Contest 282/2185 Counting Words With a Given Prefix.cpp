// MY solution

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.size();
        int cnt = 0;
        
            
        for(string x : words){
            bool flag = true;
            if(x.size() >= pref.size()){
                for(int i = 0; i < n;i++){
                    if(pref[i] != x[i])
                        flag = false;
                }
                if(flag == true)
                    cnt++;
            }
            
        }
        return cnt;
    }
};

/////////////////////////////////////////////
// online solution 

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(auto & word:words)
            if(word.find(pref)==0)
                ans++;
        return ans;
    }
};