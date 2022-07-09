#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
        unordered_map<int, list<pair<int,int>>> adj;

        void addEdge(int u, int v, int weight){
            adj[u].push_back(make_pair(v, weight));
        }

        void printAdj(){
            for(auto i : adj){
                cout<<i.first<<" : ";
                for(auto x : i.second){
                    cout<<"("<<x.first<<","<<x.second<<"), ";
                }
                cout<<endl;
            }
        }
        void dfs(int i , vector<int> &visited, stack<int>& stk){
            visited[i] = 1;

            for(auto x : adj[i]){
                if(!visited[x.first])
                    dfs(x.first, visited, stk);
            }

            stk.push(i);
        }

};

int main(){
    Graph G;
    
    G.addEdge(1, 3, 6);

    G.addEdge(1, 2, 2);

    G.addEdge(0, 1, 5);

    G.addEdge(0, 2, 3);

    G.addEdge(3, 4, -1);

    G.addEdge(2, 4, 4);

    G.addEdge(2, 5, 2);

    G.addEdge(2, 3, 7);

    G.addEdge(4, 5, -2);

    int n  = 6;
    vector<int> visited(n , 0);

    stack<int> s;

    

    for(int i = 0; i < n ; i++){
        if(!visited[i]){
            G.dfs(i , visited, s);
        }
    }
    int src = 1;

    vector<int> dist(n, INT_MAX);

    dist[src] = 0;

    while(!s.empty()){
        int top = s.top();
        s.pop();

        if(dist[top] != INT_MAX){
            for(auto x : G.adj[top]){
                dist[x.first] = min(dist[x.first], dist[top]+x.second);
            }
        }
        
    }

    cout<<"\nAnswer is :\n";

    for(int i = 0; i< n;i++){
        cout<<dist[i]<<" ";
    }


    return 0;
}