#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr, int n) {
    vector<int> ans;
    stack<int> s;

    for(int i = n - 1; i >= 0; i--)
    {
        if(s.empty())
        {
            ans.push_back(-1);
        }
        else if(!s.empty() && s.top() < arr[i])
        {
            ans.push_back(s.top());
        }
        else
        {
            while(!s.empty() && s.top() >= arr[i])
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

    reverse(ans.begin(), ans.end());
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

// Smaller Code with same implementation
/*
    vector<int> nextSmallerElement(vector<int> &arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while(s.top() >= curr && !s.empty())
            {
                s.pop();
            }
            ans[i] = s.top();
            s.push(curr);
        }
        
        return ans;
    }
*/