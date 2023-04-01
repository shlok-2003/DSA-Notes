#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
    //! For detecting the cycle in directed graph, we have to use Kahn Algorithm, now the catch is, after creating the topological
    //! vector for the directed graph, if the vector size doesn't matches the original number of nodes from the input, then 
    //! we can say that cycle was present

    int indegree[V] = {0};
    for(int i = 0; i < V; i++)
        for(auto x : adj[i])
            indegree[x]++;
    
    queue<int> q;
    for(int i = 0; i < V; i++)
        if(indegree[i] == 0)
            q.push(i);
    
    vector<int> topo;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);
        for(auto x : adj[node])
        {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);
        }
    }

    return topo.size() != V;            //! i.e the number of nodes in topo must be less for a cycle to be present
}

int main() {
    int node, edge;
    cout << "Enter the number of node: ";
    cin >> node;

    cout << "Enter the number of edge: ";
    cin >> edge;

    vector<int> adj[node];      //? 0-base indexed graph
    for(int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        //! Directed graph
        adj[u].push_back(v);
    }

    if(isCycle(node, adj))
        cout << "Cycle is present" << endl;
    else    
        cout << "Cycle not present" << endl;
}