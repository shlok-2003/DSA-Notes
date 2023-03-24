#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]) {
    vis[src] = 1;

    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjacentNode : adj[node])
        {
            if(!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }    
            else if(parent != adjacentNode)
                return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    int vis[V] = {0};

    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
            if(detect(i, adj, vis)) return true;
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