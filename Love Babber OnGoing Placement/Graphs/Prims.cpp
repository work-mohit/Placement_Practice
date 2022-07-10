#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // make adj list 
    
    unordered_map<int, list<pair<int,int>>> adjlist;
    for(int i = 0; i<g.size(); i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }
    
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);
    
    key[1] = 0;
    parent[1] = -1;
    
    for(int k = 1; k < n; k++){
         int mini = INT_MAX, u;
        for(int i = 1; i<= key.size();i++){
            if(mst[i] == false && key[i] < mini){
                mini = key[i];
                u = i;
            }
        }
        mst[u] = true;
        
        for(auto x : adjlist[u]){
            int idx = x.first;
            int weight = x.second;
            if(mst[idx] == false && weight < key[idx]){
                key[idx] = weight;
                parent[idx] = u;
            }
        }
    }

    vector<pair<pair<int, int>, int>> minBST;
    for(int i = 2; i <= n; i++){
        int u = parent[i];
        int v = i;
        int w = key[i];
        minBST.push_back(make_pair(make_pair(u, v), w));
    }
    return minBST;
}
