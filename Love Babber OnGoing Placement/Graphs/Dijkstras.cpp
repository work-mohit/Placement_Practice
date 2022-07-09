#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int src) {
    // make adj list
    
    unordered_map<int, vector<pair<int, int>>> umap;
    for(int i = 0; i < edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        umap[u].push_back(make_pair(v , w));
        umap[v].push_back(make_pair(u , w));
    }
    // to keep the unique combo + sorted order of (distnode , node)
    set<pair<int, int>> s;   // (distnode , node)
    // to keep the distance from source to all the other nodes
    vector<int> dist(vertices,INT_MAX);
    dist[src] = 0;
    
    s.insert(make_pair(0, src));
    // run till set gets empty
    while(!s.empty()){
        auto front = *(s.begin());  // itrator at first element and dereferenced it 
        int nodeDistance = front.first;
        int node = front.second;
        s.erase(s.begin()); // remove from the set
        
        for(auto x : umap[node]){
            int ele = x.first;
            int weight = x.second;

            // check the condition 
            // if for a node 4 if there is a pair in the set (5, 4)
            // but we fount less distance lets say 3 distance then the pair will be (3,4)
            // since we only need one and only pair for any particular node
            // we find the old one from the set and remove it 
            // and insert the new pair
            // if there is no previous pair for 4 then we just insert the pair 
        
            if((nodeDistance + weight) < dist[ele]){
                auto temp = s.find(make_pair(dist[ele], ele));   
                
                if(temp != s.end()){
                    s.erase(temp);
                }
                    
                dist[ele] = nodeDistance + weight;
                s.insert(make_pair(dist[ele], ele));
            }    
        }    
    }
    return dist;
}
