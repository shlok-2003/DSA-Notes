#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int n) {
    // Next Smallest Element to Left
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

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, n) << endl;
    return 0;
}