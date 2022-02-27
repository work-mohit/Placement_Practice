class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m;
        for(auto x : s)
            m[x]++;
        for(auto x : t)
            m[x]--;
            
        int cnt= 0;
        for(auto x: m)
            cnt += abs(x.second);
        return cnt;
    }
};