#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> topologicalSort(int V, vector<int> adj[]) {
    //! In Kahn algorithm, we create a indegree vector, which stores the number of edges coming to a node;
    //! Now, we initialize a queue, which includes all the nodes, which have 0 indegree. There would be at least one node with 
    //! indegree 0, as the graph is a Directed Acyclic Graph(DAG). So, this holds true for all such graph

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
        
        //! Whenever we are removing an element from the queue, we would also decrease the indegree for all the nodes connecting to the 
        //! popped element. This is sort of deleting the edge between the popped node and the connected nodes to it.
        for(auto x : adj[node])
        {
            indegree[x]--;
            if(indegree[x] == 0)
                q.push(x);      //! Wherever the indegree becomes 0, we push it in queue. There would be atleast one node, which would 
                                //! follow this, as this is Directed Acyclic Graph
        }
    }

    return topo;
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

    vector<int> ans = topologicalSort(node, adj);

    for(auto x : ans)
        cout << x << " ";
}