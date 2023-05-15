#include <bits/stdc++.h>
using namespace std;

int prims(int V, vector<pair<int, int>> adj[]) {
    vector<int> vis(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});        //? {weight, node} ----> starting node is 0 here

    int sum = 0;
    while(!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(vis[node] == 1)  continue;
        vis[node] = 1;

        sum += weight;
        for(auto it : adj[node])
        {
            int n = it.first;
            int w = it.second;

            if(!vis[n])
                pq.push({w, n});
        }
    }

    return sum;
}

int main() {
    int node, edges;
    cout << "Enter the number of nodes: ";
    cin >> node;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<pair<int, int>> adj[node];
    for(int i = 0; i < node; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight});
    }

    int minWeight = prims(node, adj);

    cout << "Weight of Minimum Spanning Tree is: " << minWeight << endl;
}