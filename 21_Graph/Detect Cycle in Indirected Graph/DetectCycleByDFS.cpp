#include <iostream>
#include <vector>
using namespace std;

bool detect(int node, int parent, vector<int> adj[], int vis[]) {
    vis[node] = 1;

    for(auto adjacentNode : adj[node])
    {
        if(!vis[adjacentNode])
        {
            if(detect(adjacentNode, node, adj, vis))    return true;
        }
        else if(parent != adjacentNode) return true;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
            if(detect(i, -1, adj, vis)) return true;
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

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(isCycle(node, adj))
        cout << "Cycle is present" << endl;
    else    
        cout << "Cycle not present" << endl;
}