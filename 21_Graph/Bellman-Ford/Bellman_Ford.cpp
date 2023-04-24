#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    
    for(int i = 0; i < V-1; i++)
    {
        for(auto it : edges)
        {
            int u = it[0], v = it[1], dis = it[2];
            if(dist[u] + dis < dist[v])
            {
                dist[v] = dist[u] + dis; 
            }
        }
    }
    
    // For checking negative cycle
    for(auto it : edges)
    {
        int u = it[0], v = it[1], dis = it[2];
        if(dist[u] + dis < dist[v])
            return {-1};
    }
    
    return dist;
}

int main() {
    int node, edge, source;
    cout << "Enter the number of node: ";
    cin >> node;

    cout << "Enter the number of edge: ";
    cin >> edge;

    cout << "Enter the source vertex: ";
    cin >> source;

    vector<vector<int>> edges;      //? For creating the edges
    for(int i = 0; i < edge; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;

        edges.push_back({u, v, weight});
    }

    vector<int> minDist = bellman_ford(node, edges, source);

    for(int &i : minDist)
        cout << i << " ";
    cout << endl;
}