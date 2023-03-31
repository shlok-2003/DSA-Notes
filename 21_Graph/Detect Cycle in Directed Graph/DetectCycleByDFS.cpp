#include <iostream>
#include <vector>
using namespace std;

bool detect(int node, vector<int> adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    for(auto x : adj[node])
    {
        if(!vis[x]) {
            if(detect(x, adj, vis, pathVis) == true)    return true;
        }
        else if(pathVis[x])
            return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
            if(detect(i, adj, vis, pathVis)) return true;
    }

    return false;
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