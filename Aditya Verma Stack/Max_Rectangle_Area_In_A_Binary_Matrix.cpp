class Solution {
private:
    int MAH(vector<int>& arr){
        int n = arr.size();
        vector<int> left(n), right(n);
        //NSL
        stack<pair<int,int>> s;
    
        for (int i = 0; i < arr.size(); i++) {
            if (s.size()!= 0) {
                while (s.size() > 0 && s.top().first >= arr[i]) {
                    s.pop();
                }
            }
            left[i] = s.empty() ? -1 : s.top().second;
            s.push({arr[i],i}); 

        }

        while(!s.empty())s.pop();
        // NSR
        for (int i = arr.size()-1; i >= 0; i--) {
            if (s.size()!= 0) {
                while (s.size() > 0 && s.top().first >= arr[i]) {
                    s.pop();
                }
            }
            right[i] = s.empty() ? n : s.top().second;
            s.push({arr[i], i}); 
        }
        
       
        int maxarea= -1; 
        for(int i = 0 ; i < arr.size();i++){
            maxarea = max(maxarea, (arr[i] * (right[i] - left[i] -1))); 
        }
        return maxarea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> v;
        int n = matrix.size();
        int m = matrix[0].size();
       
        for(int i = 0; i<m ; i++)
            v.push_back(matrix[0][i]-'0');
        
        int mx = MAH(v);
        cout<<mx<<" ";
        for(int i = 1; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(matrix[i][j] == '0')
                    v[j] = 0;
                else
                    v[j] = v[j] + (matrix[i][j]-'0');
            }
            mx = max(mx , MAH(v));
        }
        return mx;
    }
};