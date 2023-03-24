#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph {
private:
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v, bool direction) {
        //? direction = 0 is for undirected graph
        //? direction = 1 is for directed graph

        //! Create a graph form u to v
        adj[u].push_back(v);
        if(direction == 0)          //? if the direction is 0 then add an edge from v to u
            adj[v].push_back(u);    
    }

    void helper(unordered_map<int, vector<int>>& adj, unordered_map<int, bool>& visited, vector<int>& bfs, int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty())
        {
            int frontNode = q.front();
            q.pop();

            bfs.push_back(frontNode);
            for(auto &j : adj[frontNode])
                if(!visited[j])
                    q.push(j), visited[j] = true;
        }
    }

    void printBFS(int nodes, vector<int>& bfs) {
        unordered_map<int, bool> visited;
        
        for(int i = 0; i < nodes; i++)          //? BFS 
            if(!visited[i])
                helper(adj, visited, bfs, i);

        for(auto &x : bfs)                      //? Print the bfs traversalarray
            cout << x << " ";
    }
};

int main() {
    int node;
    cout << "Enter the number of nodes: ";
    cin >> node; 

    int edge;
    cout << "Enter the number of edges: ";
    cin >> edge;

    Graph g;

    for(int i = 0; i < edge; i++)
    {
        int u, v;
        cin >> u >> v;

        g.addEdge(u, v, 0);     //? creating a directional graph
    }

    vector<int> bfs;
    g.printBFS(node, bfs);
}