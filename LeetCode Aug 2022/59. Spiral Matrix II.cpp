class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int rows = 0, rowe = n-1, cols= 0, cole = n-1;
        
        int idx = 1;
        
        vector<vector<int>> res(n , vector<int>(n, 0));
        
        while(rows <= rowe && cols <= cole){
            
            for(int i = cols; i <= cole; i++){
                res[rows][i] = idx++;
            }
            rows++;
            for(int i = rows; i<=rowe; i++){
                res[i][cole] = idx++;
            }
            cole--;
            
            for(int i = cole; i>= cols; i--){
                res[rowe][i] = idx++;
            }
            rowe--;
            for(int i = rowe; i>= rows; i--){
                res[i][cols] = idx++;
            }
            cols++;
        }
        return res;
    }
};