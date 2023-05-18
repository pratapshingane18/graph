#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;
template <typename T>

class graph{

    public:
    unordered_map<T, list<T>> adj;

    void addEdge(T v, T u, bool direction){
        //direction 0 - undirected graph
        //direction 1 - directed graph

        // creating edge from u to v or v to u if g is undirected

        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout<<i.first<<"->";
            for(auto j: i.second){
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }

};



int main(){

    int n ;
    cout<<"Enter Number of Nodes"<<endl;
    cin>>n;

    int m;
    cout<<"Enter Number of Edges"<<endl;
    cin>>m;

    cout<<"Enter Directions"<<endl;
    
    graph<int> g;
    for(int i=0; i < m; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v,0);

    }

    // printing adj list
    cout<<"Adjecency List:"<<endl;

    g.printAdjList();

    return 0;
}