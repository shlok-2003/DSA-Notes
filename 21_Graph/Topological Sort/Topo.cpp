#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], stack<int>& s) {
    vis[node] = 1;
    
    for(auto x : adj[node])
    {
        if(!vis[x])
            dfs(x, adj, vis, s);
    }
    s.push(node);
}

vector<int> topologicalSort(int node, vector<int> adj[]) {
    int vis[node] = {0};
    stack<int> s;

    for(int i = 0; i < node; i++)
        if(!vis[i])
            dfs(i, adj, vis, s);

    vector<int> ans;
    while(!s.empty())
            ans.push_back(s.top()), s.pop();
    return ans;
}

int main() {
    int node;
    cout << "Enter the number of nodes: ";
    cin >> node; 

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    //! In Topological Sorting all the edges u -> v are displayed in a way where the node u is print before all its children.
    //! Topological sorting cannot work on undirected graph, as we would not know, which node comes first;
    //! Same goes for cyclic graph, topological Sort cannot work on them. 

    vector<int> adj[node];
    for(int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        //! Topological sort only works for directed acyclic graph
    }

    vector<int> ans = topologicalSort(node, adj);

    for(auto x : ans)
        cout << x << " ";
}