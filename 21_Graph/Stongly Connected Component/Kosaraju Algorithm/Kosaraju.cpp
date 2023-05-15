#include<bits/stdc++.h>
using namespace std;

//! Strongly Connected Components are only valid for Directed Graphs

//? Strongly Connected Component (SCC) are those components in which, every pair of vertex is reachable 
//? to each other.

//* Thought Process ----> Consider a graph which is shown in Graph_Diagram.drawio. As we can see, if we call the 
//* dfs from the node 0, we can travel to all the nodes present in a graph such that:
//*     SCC(0) ---> SCC(3) ---> SCC(4) ---> SCC(7) as, this are the possible Components.
//* . But, this doesn't tell anything about
//* SCC. But if we reverse all the edges such as in second graph in Graph_Diagram.drawio, we can see that, 
//* we cannot travel to other SCC's, so, this shows that by reversing the edges, we can get the possible SCC's. 
//* Also, we can still reach each pair of vertex inside a SCC. 

//? Algorithm:  Step1 ---> Sort all the edges according to their finishing time
//?             Step2 ---> Reverse the graph
//?             Step3 ---> Do the DFS according to the stored edges

void dfsToAdd(int node, vector<int> adj[], vector<int> &vis, stack<int> &st) {
    vis[node] = 1;

    for(auto it : adj[node])
        if(!vis[it])
            dfsToAdd(it, adj, vis, st);

    st.push(node);
}

void dfs(int node, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;

    for(auto it : adj[node])
        if(!vis[it])
            dfs(it, adj, vis);
}

int kosaraju(int node, vector<int> adj[]) {
    vector<int> vis(node, 0);
    stack<int> st;

    for(int i = 0; i < node; i++)
        if(!vis[i])
            dfsToAdd(i, adj, vis, st);

    vector<int> adjRev[node];
    for(int i = 0; i < node; i++)
    {
        vis[i] = 0;
        for(auto it : adj[i])   
            adjRev[it].push_back(i);
    }

    int scc = 0;
    while(!st.empty())
    {
        int top = st.top();
        st.pop();

        if(!vis[top])
            scc++, dfs(top, adjRev, vis);
    }

    return scc;
}

int main(){
    int node, edges;
    cout << "Enter the number of nodes: ";
    cin >> node;

    cout << "Enter the number of edges: ";
    cin >> edges;

    vector<int> adj[node];
    for(int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        //! Directed graph
        adj[u].push_back(v);
    }

    int scc = kosaraju(node, adj);

    cout << scc << endl;
    return 0;
}