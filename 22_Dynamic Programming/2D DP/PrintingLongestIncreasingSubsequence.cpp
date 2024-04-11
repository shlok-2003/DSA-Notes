#include <bits/stdc++.h>
using namespace std;

//! Same as LongestIncreasingSubsequence.cpp
//! Now we will have to keep a track of the indexes which are being included in the ans_idx, this can be done using another vector
//? This approach is very similar to union-find, where we keep a track of the parent of each element

int optimized(int n, vector<int> &arr, vector<int> &dp, vector<int> &track)
{

    int ans_idx = 0; //? ans == 1 because the length of the longest increasing subsequence can be 1 at least
    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[idx] > arr[prev] && 1 + dp[prev] > dp[idx])
            {
                // dp[idx] = max(dp[idx], 1 + dp[prev]);
                track[idx] = prev;
                dp[idx] = 1 + dp[prev];
            }
        }

        if (dp[idx] > dp[ans_idx])
        {
            ans_idx = idx;
        }
    }

    return ans_idx;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }

    vector<int> dp(n, 1);
    vector<int> track(n);

    for (int i = 0; i < n; i++)
    {
        track[i] = i;
    }

    int max_ans_index = optimized(n, arr, dp, track);

    int curr = max_ans_index;
    vector<int> ans;

    ans.push_back(arr[curr]);
    
    while (curr != track[curr])
    {
        curr = track[curr];
        ans.push_back(arr[curr]);
    }

    cout << "The longest increasing subsequence is: ";
    reverse(ans.begin(), ans.end());
    for(auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}