#include <bits/stdc++.h>
using namespace std;

vector<int> helper(int V, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});    //? {dist, source}
    //! source is 1 and destination is n;

    vector<int> dist(V + 1, 1e9);
    dist[1] = 0;

    vector<int> parent(V + 1);
    for(int i = 0; i <= V; i++)
        parent[i] = i;
    
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
                parent[n] = node;
                pq.push({dist[n], n});
            }
        }
    }

    if(dist[V] == 1e9)  return {-1};

    vector<int> path;
    int n = V;                  //? For creating the path
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