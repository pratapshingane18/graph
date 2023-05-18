#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

class graph{
    int numNodes;
    vector<vector<int>> adjList;

    public:

    graph(int startNode){
        numNodes = startNode;
        adjList.resize(numNodes);

    }

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void bfs(int startNode){
        vector<bool> Visited(numNodes,false);
        queue<int> qu;


        Visited[startNode] = true;
        qu.push(startNode);


        while(!qu.empty()){
            int currNode = qu.front();
            qu.pop();
            cout<<currNode<< " ";

            for(int i =0; i < adjList[currNode].size(); i++){
                int adjNode = adjList[currNode][i];

                if(!Visited[adjNode]){
                    Visited[adjNode] = true;
                    qu.push(adjNode);
                }
            }
        }



    }

};

int main(){
    int nodes;
    cout<<"Enter Number of Nodes:"<<endl;
    cin>>nodes;

    int edges;
    cout<<"Enter Number of Edges"<<endl;
    cin>>edges;

    graph g(nodes);
    for(int i = 0 ; i < edges; i++){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
    }

    int startNode;
    cout<<"Enter StartNode"<<endl;
    cin>>startNode;

    g.bfs(startNode);
    return 0;
}