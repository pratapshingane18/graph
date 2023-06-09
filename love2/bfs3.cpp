#include <iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;


class graph {
    int numNodes;
    vector<vector<int>> adj;

    public:

    graph(int Nodes){
        numNodes = Nodes;
        adj.resize(numNodes);
    }

    void addedge(int v, int u){
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    void bfs(int startNode){
        vector<bool> visited(numNodes,false);
        queue<int> qu;

        
        visited[startNode] = true;
        qu.push(startNode);

        while(!qu.empty()){
            int currNode = qu.front();
            qu.pop();
            cout<<currNode<<" ";
            for(int i =0; i < adj[currNode].size(); i++){
                 int adjNode = adj[currNode][i];

                 if(!visited[adjNode]){
                    visited[adjNode] = true;
                    qu.push(adjNode);
                  }

            }
           
        }



    }

};
int main(){
    int nodes;
    cout<<"Enter number of Nodes:"<<endl;
    cin>>nodes;


    int edges;
    cout<<"Enter number of edges:"<<endl;
    cin>>edges;

    graph g(nodes);

    for(int i =0; i < edges; i++){
        int v,u;
        cout<<"Enter all directions"<<endl;
        cin>>v>>u;
        g.addedge(v,u);
    }

    int startNode;
    cout<<"Enter StartNode"<<endl;
    cin>>startNode;

    g.bfs(startNode);




}