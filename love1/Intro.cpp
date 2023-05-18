#include<iostream>
#include<unordered_map>
#include<list>


using namespace std;

class graph{

    public:
    unordered_map<int, list<int>> adj;

    void addEdge(int v, int u, bool direction){
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

    
    return 0;
}