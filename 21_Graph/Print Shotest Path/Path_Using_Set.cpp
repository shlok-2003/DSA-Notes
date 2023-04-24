#include <bits/stdc++.h>
using namespace std;

vector<int> helper(int V, vector<pair<int, int>> adj[]) {
    set<pair<int, int>> set;
    set.insert({0, 1});         // Node starts from 1 to n

    vector<int> dist(V + 1, 1e9);
    dist[1] = 0;

    vector<int> parent(V + 1);
    for(int i = 0; i <= V; i++) parent[i] = i;

    while(!set.empty())
    {
        auto it = *(set.begin());
        int distance = it.first;
        int node = it.second;
        set.erase(it);

        for(auto adjNode : adj[node])
        {
            int w = adjNode.second;
            int n = adjNode.first;
            if(distance + w < dist[n])
            {
                if(dist[n] != 1e9)  set.erase({dist[n], n});
                dist[n] = distance + w;
                set.insert({dist[n], n});
                
                parent[n] = node;
            }
        }
    }

    vector<int> path;
    int n = V;
    while(parent[n] != n)
    {
        path.push_back(n);
        n = parent[n];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    
    return path;
}

int main() {
    int node, edge;
    cout << "Enter the number of node: ";
    cin >> node;

    cout << "Enter the number of edges: ";
    cin >> edge;

    vector<pair<int, int>> adj[node + 1];
    for(int i = 0; i < edge; i++)
    {
        int u, v, dist;
        cin >> u >> v >> dist;

        //? undirected graph
        adj[u].push_back({v, dist});
        adj[v].push_back({u, dist});
    }

    vector<int> path = helper(node, adj);

    for(int &i : path)
        cout << i << " ";
    cout << endl;
}