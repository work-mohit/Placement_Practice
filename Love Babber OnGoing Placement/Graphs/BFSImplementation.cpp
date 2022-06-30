// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // adjancy list banao
    unordered_map<int, set<int>> adjlist(vertex);
    vector<int> res;
    for(auto i: edges){
        adjlist[i.first].insert(i.second);
        adjlist[i.second].insert(i.first);
    }
    // visited map and queue declare kro 
    vector<bool> visited(vertex, false);
    queue<int> q;
    // bfs implement kro
    q.push(0);
    visited[0] = true;
    while(!q.empty()){
        int d = q.front();
        q.pop();
        res.push_back(d);
        for(int x: adjlist[d]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }  
    }
    for(int i = 0; i<visited.size(); i++)
        if(!visited[i])
            res.push_back(i);
    return res;
    
}