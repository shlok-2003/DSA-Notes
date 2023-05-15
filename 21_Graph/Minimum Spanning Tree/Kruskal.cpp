#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
	vector<int> rank, parent, size;

public:
	DisjointSet(int n) {
		rank.resize(n+1, 0); size.resize(n+1); parent.resize(n+1);	// for both (0 and 1)-based indexing
		for(int i = 0; i <= n; i++)	{
			parent[i] = i, size[i] = 1;
		}
	}

	int findUParent(int node) {						// Find Ultimate Parent
		if(node == parent[node])	return node;

		return parent[node] = findUParent(parent[node]);
	}

	// Time Complexity of Union_BySize and Union_ByRank is O(4'alpha')
	void union_ByRank(int u, int v) {				// Union By Rank
		int ulp_u = findUParent(u);
		int ulp_v = findUParent(v);

		if(ulp_u == ulp_v)	return;

		if(rank[ulp_u] < rank[ulp_v])
			parent[ulp_u] = ulp_v;
		else if(rank[ulp_u] > rank[ulp_v])
			parent[ulp_v] = ulp_u;
		else
			parent[ulp_v] = ulp_u, rank[ulp_u]++;
	}

	void union_BySize(int u, int v) {				// Union By Size
		int ulp_u = findUParent(u);
		int ulp_v = findUParent(v);

		if(ulp_u == ulp_v)	return;

		if(size[ulp_u] < size[ulp_v])
			parent[ulp_u] = ulp_v, size[ulp_v] += size[ulp_u];
		else if(size[ulp_u] >= size[ulp_v])
			parent[ulp_v] = ulp_u, size[ulp_u] += size[ulp_v];		// same conditions will apply for '>' and '=' conditions. 
																	// So, merge it in same condition
	}
};

int kruskal(int V, vector<pair<int, int>> adj[]) {
    DisjointSet ds(V);

    vector<pair<int, pair<int, int>>> edges;
    for(int i = 0; i < V; i++)
    {   
        int node = i;
        for(auto it : adj[i])
        {
            int adjNode = it.first;
            int w = it.second;

            edges.push_back({w, {node, adjNode}});      // no need to make the graph undirected as we are accounting all the edges
        }
    }

    int sum = 0;
    sort(edges.begin(), edges.end());
    for(auto it : edges)
    {
        int weight = it.first;
        int node = it.second.first;
        int adjNode = it.second.second;

        if(ds.findUParent(node) == ds.findUParent(adjNode))
            continue;
        
        ds.union_BySize(node, adjNode);
        sum += weight;
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

    int minWeight = kruskal(node, adj);

    cout << "Weight of Minimum Spanning Tree is: " << minWeight << endl;
}