#include <bits/stdc++.h>
using namespace std;

vector<int> Dijkstra(int V, vector<pair<int, int>> adj[], int source) {
    set<pair<int, int>> set;
    set.insert({0, source});

    vector<int> dist(V, 1e9);
    dist[source] = 0;

    while(!set.empty())
    {
        auto it = *(set.begin());
        int distance = it.first;
        int node = it.second;
        set.erase(it);

        for(auto x : adj[node])
        {
            int w = x.second;
            int n = x.first;
            if(distance + w < dist[n])
            {
                if(dist[n] != 1e9)  set.erase({dist[n], n});
                dist[n] = distance + w;
                set.insert({dist[n], n});
            }
        }
    }

    return dist;
}

int main() {
    int node, edge;
    cout << "Enter the number of node: ";
    cin >> node;

    cout << "Enter the number of edges: ";
    cin >> edge;

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    vector<pair<int, int>> adj[node];
    for(int i = 0; i < edge; i++)
    {
        int u, v, dist;
        cin >> u >> v >> dist;

        //? undirected graph
        adj[u].push_back({v, dist});
        adj[v].push_back({u, dist});
    }

    vector<int> minDist = Dijkstra(node, adj, source);

    for(int &i : minDist)
        cout << i << " ";
    cout << endl;
}