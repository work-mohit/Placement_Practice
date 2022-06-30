#include<bits/stdc++.h>
using namespace std;

template <typename T>
class graph{
    public:
        unordered_map<T , vector<T> > adj;
        void addEdge(T v , T u, bool direction){
            adj[v].push_back(u);
            if(direction == 0)
                adj[u].push_back(v);
        }
        void printAdjancyList(){
            for(auto x: adj){
                cout<<x.first<<"-->"<<" ";
                for(auto i: x.second){
                    cout<<i<<", ";
                }
                cout<<endl;
            }
        }
};

int main(){
    int n,e;
    graph<int> g;
    cout<<"Enter the no of nodes:"<<endl;
    cin>>n;
    cout<<"Enter the no of edges:"<<endl;
    cin>>e;
    cout<<"Enter the start and destination of the "<<e<<" edges:"<<endl;
    int v, u;
    for(int i = 0; i< e; i++){
        cin>>v>>u;
        g.addEdge(v, u, 1);
    }
    g.printAdjancyList();
}