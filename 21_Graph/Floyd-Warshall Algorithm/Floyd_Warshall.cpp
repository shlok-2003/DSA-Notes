#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == -1)          //not reachable
                matrix[i][j] = 1e9;
            if(i == j)
                matrix[i][j] = 0;
        }
    }

    // main floyd_warshall implementation
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // For checking negative cycle
    for(int i = 0; i < n; i++) 
    {
        if(matrix[i][i] < 0) 
        {
            cout << "!-- Negative cycle present --!" << endl;
            break;
        }            
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(matrix[i][j] == 1e9)
                matrix[i][j] = -1;
        }
    }
}

int main() {
    int node, edge;
    cout << "Enter the number of nodes: ";
    cin >> node;

    cout << "Enter the adjacency matrix" << endl;
    vector<vector<int>> matrix(node, vector<int>(node, 0));
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            cin >> matrix[i][j];
        }
    }

    floyd_warshall(matrix);
    cout << "The shortest distance is: " << endl;
    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < node; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}