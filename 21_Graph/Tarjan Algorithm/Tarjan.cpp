#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int timer;
vector<vector<int>> ans;

void tarjans(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for(const auto &it : adj[node])
    {
        if(it == parent)    continue;
        if(!vis[it])
        {
            tarjans(it, node, adj, vis, tin, low);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node])
            {
                ans.push_back({ node, it });
            }
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> isBridge(int V, vector<int> adj[]) {
    ans.clear();

    vector<int> vis(V, 0), tin(V), low(V);
    for(int i = 0; i < V; i++)
    {
        if(!vis[i])
        {
            timer = 1;
            tarjans(i, -1, adj, vis, tin, low);
        }
    }    

    return ans;
}

int main() {
    int node, edge;
    cout << "Enter the number of node: ";
    cin >> node;

    cout << "Enter the number of edge: ";
    cin >> edge;

    vector<int> adj[node];
    for(int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }   

    //! This algorithm is used to evaluate the bridge edges in a graph

    vector<vector<int>> bridges = isBridge(node, adj);
    
    cout << "The bridge edges are: \n";
    for(const auto &it : bridges)
    {
        cout << it[0] << " " << it[1] << endl;
    }
}