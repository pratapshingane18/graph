#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Graph {
private:
    int numNodes;
    vector<vector<int>> adjList;

public:
    Graph(int nodes) {
        numNodes = nodes;
        adjList.resize(numNodes);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void BFS(int startNode) {
        vector<bool> visited(numNodes, false);
        queue<int> bfsQueue;

        visited[startNode] = true;
        bfsQueue.push(startNode);

        while (!bfsQueue.empty()) {
            int currentNode = bfsQueue.front();
            bfsQueue.pop();
            cout << currentNode << " ";

            for (int i = 0; i < adjList[currentNode].size(); ++i) {
                int adjacentNode = adjList[currentNode][i];
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = true;
                    bfsQueue.push(adjacentNode);
                }
            }
        }
    }
};

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes in the graph: ";
    cin >> numNodes;

    Graph graph(numNodes);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (node u to node v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int startNode;
    cout << "Enter the starting node for BFS: ";
    cin >> startNode;

    cout << "BFS traversal starting from node " << startNode << ": ";
    graph.BFS(startNode);

    return 0;
}
