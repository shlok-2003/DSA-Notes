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

int main() {
	DisjointSet ds(7);
	ds.union_BySize(1, 2);
	ds.union_BySize(2, 3);
	ds.union_BySize(4, 5);
	ds.union_BySize(6, 7); 
	ds.union_BySize(5, 6);

	if(ds.findUParent(3) == ds.findUParent(7))
		cout << "Same\n";	
	else
		cout << "Not Same\n";

	ds.union_BySize(3, 7);

	if(ds.findUParent(3) == ds.findUParent(7))
		cout << "Same\n";
	else
		cout << "Not Same\n";
}