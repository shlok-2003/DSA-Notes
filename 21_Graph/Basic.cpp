#include <iostream>
#include <map>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adj;

public:
    void addEdge(int u, int v, bool direction) {
        //? direction = 0 is for undirected graph
        //? direction = 1 is for directed graph

        //! Create a graph form u to v
        adj[u].push_back(v);
        if(direction == 0)      //? if the direction is 0 then add an edge from v to u
            adj[v].push_back(u);
    }

    void printAdjacencyList() {
        for(auto& i: adj)
        {
            cout << i.first << "-> ";
            for(auto& j: i.second)
                cout << j << ", ";
            cout << endl;
        }
    }
};

int main() {
    int node;
    cout << "Enter the number of nodes: ";
    cin >> node; 

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    Graph g;

    for(int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);     //? creating a directional graph
    }

    g.printAdjacencyList();

    return 0;
}