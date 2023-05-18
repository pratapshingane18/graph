#include <iostream>
#include <list>
using namespace std;

class Graph {
    int V; // number of vertices

    // pointer to an array containing adjacency lists
    list<int>* adj;

    // recursive function used by DFS
    void DFSUtil(int v, bool visited[]);

public:
    Graph(int V); // constructor
    void addEdge(int v, int w); // function to add an edge to the graph
    void DFS(int v); // DFS traversal
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // add w to v's adjacency list
}

void Graph::DFSUtil(int v, bool visited[]) {
    // mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";

    // recursively visit all the adjacent vertices of the current vertex
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i])
            DFSUtil(*i, visited);
    }
}

void Graph::DFS(int v) {
    // create a visited array and initialize all vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}

int main() {
    // create a graph given in the example
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS traversal starting from vertex 2: ";
    g.DFS(2);
    
    return 0;
}
