 vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>> ans;
        
//         if(interval.size()==0)
//             return ans;
        
//         sort(interval.begin(),interval.end());
        
//         ans.push_back(interval[0]);
//         int j=0;
//         for(int i=1;i<interval.size();i++)
//         {
//             if(ans[j][1]>=interval[i][0])  // overlapping
//                 ans[j][1]=max(ans[j][1],interval[i][1]);  
//             else
//             {
//                 j++;
//                 ans.push_back(interval[i]);  // not overlapping so just pushing the interval into result
//             }
//         }
//         return ans;
    vector<vector<int>> resultVec;
    if(intervals.size() == 0)
        return resultVec;
    
    sort(intervals.begin(), intervals.end());
    vector<int> tempInterval = intervals[0];
    
    for(auto it : intervals){
        if(it[0] <= tempInterval[1])
            tempInterval[1] = max(it[1],tempInterval[1]);
        else{
            resultVec.push_back(tempInterval);
            tempInterval = it;
        }
            
    }
    resultVec.push_back(tempInterval);
    return resultVec;
}