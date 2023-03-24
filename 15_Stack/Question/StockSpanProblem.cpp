#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n) {
    vector<int> idx(n);
    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && s.top().first <= arr[i])
        {
            s.pop();
        }
        if(s.empty())
            idx[i] = -1;
        else
            idx[i] = s.top().second;
        s.push(make_pair(arr[i], i));
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++)
    {
        ans[i] = i - idx[i];
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = solve(arr, n);
    for(int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}