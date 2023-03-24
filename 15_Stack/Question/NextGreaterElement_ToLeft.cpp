#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n) {
    vector<int> ans;
    stack<int> s;

    for(int i = 0; i < n; i++)
    {
        if(s.empty())
        {
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top() > arr[i])
        {
            ans.push_back(s.top());
        }
        else
        {
            while(!s.empty() && s.top() <= arr[i])
            {
                s.pop();
            }

            if(s.empty())
                ans.push_back(-1);
            else    
                ans.push_back(s.top());
        }

        s.push(arr[i]);
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
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}