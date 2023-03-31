#include <iostream>
#include <vector>
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    
    //! incomplete
}

int main() {
    int node, edge;
    cout << "Enter the number of node: ";
    cin >> node;

    cout << "Enter the number of edge: ";
    cin >> edge;

    vector<int> adj[node];      //? 0-base indexed graph
    for(int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        //! Directed graph
        adj[u].push_back(v);
    }

    if(isCycle(node, adj))
        cout << "Cycle is present" << endl;
    else    
        cout << "Cycle not present" << endl;
}