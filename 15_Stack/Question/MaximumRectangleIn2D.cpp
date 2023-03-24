#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n) {
    vector<int> left(n);
    stack<pair<int, int>> l;
    
    for(int i = 0; i < n; i++)
    {
        while(!l.empty() && l.top().first >= arr[i])
        {
            l.pop();
        }
        if(l.empty())
            left[i] = -1;
        else   
            left[i] = l.top().second;
        l.push(make_pair(arr[i], i));
    }

    // Next Smallest Element to Right
    vector<int> right(n);
    stack<pair<int, int>> r;

    for(int i = n - 1; i >= 0; i--)
    {
        while(!r.empty() && r.top().first >= arr[i])
        {
            r.pop();
        }
        if(r.empty())
            right[i] = n;
        else    
            right[i] = r.top().second;
        r.push(make_pair(arr[i], i));
    }

    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        int num =(right[i] - left[i] - 1) * arr[i];
        mx = max(num, mx);
    }

    return mx;
}

int maximum(vector<vector<int>> M, int n, int m) {
    vector<int> arr(m);
    int mx = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(M[i][j] == 0)
                arr[j] = 0;
            else    
                arr[j] += M[i][j];
        }

        mx = max(mx, solve(arr, m));
    }
    return mx;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m ,0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }
    
    cout << maximum(mat, n, m) << endl;
}