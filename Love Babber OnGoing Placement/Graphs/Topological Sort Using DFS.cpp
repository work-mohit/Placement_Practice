#include<bits/stdc++.h>
void makeadjlist(vector<vector<int>> &edges,unordered_map<int, vector<int>> &adjlist, int e){
    for(int i = 0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
    }
}
void dfs(unordered_map<int, vector<int>>& adjlist,int x, vector<int> &viz, stack<int>& stk){
    viz[x] = 1;
    for(int z : adjlist[x]){
        if(!viz[z]){
            dfs(adjlist, z , viz, stk); 
        }      
    }
    stk.push(x);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, vector<int>> adjlist;
    makeadjlist(edges, adjlist, e);
    vector<int> viz(v+1, 0);
    stack<int> stk;
    vector<int> ans;
    for(int i =0; i< v; i++){
        if(!viz[i]){
            dfs(adjlist, i, viz,stk);
        }
    }
        
    while(!stk.empty()){
        int d = stk.top();
//         cout<<d<<" ";
        ans.push_back(stk.top());
        stk.pop();
    }
    
    return ans;
}