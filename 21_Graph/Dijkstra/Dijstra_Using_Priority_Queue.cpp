#include <bits/stdc++.h>
using namespace std;

//? We can use Queue Data Structure, but it will take more time then priority_queue

vector<int> Dijkstra(int V, vector<pair<int, int>> adj[], int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dist(V);
    for(int &i : dist)  i = 1e9;

    dist[source] = 0; 
    pq.push({0, source});

    while(!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node])
        {
            int w = it.second;
            int n = it.first;
            if(distance + w < dist[n])
            {
                dist[n] = distance + w;
                pq.push({dist[n], n});
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