class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        
        for(int i = 0; i< n; i++){
            
            unordered_map<string , int> m;
            
            int duplicate = 1;

            for(int j = i + 1; j < n; j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                if(x1 == x2 && y1 == y2){
                    duplicate++;
                }  
                else{
                    int delta_x = x2 - x1;
                    int delta_y = y2 - y1;

                    int gcd = __gcd(delta_x, delta_y);
                    m[to_string(delta_x / gcd) + '_' + to_string(delta_y / gcd)]++;
                }    
            }
            ans = max(ans, duplicate);
            for (auto p : m) {
                ans = max(ans, p.second + duplicate);
            }
        }
        return ans;
    }
};