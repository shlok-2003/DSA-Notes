#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int timer;
set<int> orderedSet;

void tarjans(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, vector<int> &low, 
            vector<int> &ans) {
    
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    int child = 0;
    for(const auto &it : adj[node])
    {
        if(it == parent)    continue;
        if(!vis[it])
        {
            tarjans(it, node, adj, vis, tin, low, ans);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] && parent != -1)
            {
                orderedSet.insert(node);
            }
            child++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }

    if(parent == -1 && child > 1)
    {
        orderedSet.insert(node);
    }
}

vector<int> articulationPoint(int n, vector<int> adj[]) {
    vector<int> vis(n, 0), tin(n), low(n), ans;

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            timer = 1;
            tarjans(i, -1, adj, vis, tin, low, ans);
        }
    }

    for(const int &it : orderedSet)
        ans.push_back(it);
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

    vector<int> points = articulationPoint(node, adj);
    //? Print in sorted order
    sort(points.begin(), points.end());

    cout << "The articulation points are: \n";
    for(const int &it : points) 
    {
        cout << it << " ";
    }
}