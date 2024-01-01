#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
//! This problem is solved in most optimized way. Refer to SubsetSumEqualsK.cpp for other methods

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) 
    {
        cin >> i;
    }

    int sum = accumulate(arr.begin(), arr.end(), 0);    
    vector<int> prev(sum+1, 0), curr(sum+1, 0);

    prev[0] = curr[0] = 1;
    if(arr[0] <= sum)   prev[arr[0]] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int target = 1; target <= sum; target++)
        {
            int not_take = prev[target];
            int take = 0;

            if(arr[i] <= target) 
            {
                take = prev[target-arr[i]];
            }

            curr[target] = not_take | take;
        }

        prev = curr;
    }

    int ans = 1e8;
    for(int i = 0; i <= sum; i++)
    {
        if(prev[i] == 1)
        {
            int left = i, right = sum - i;
            ans = min(ans, abs(left - right));
        }
    }

    cout << ans << endl;

    return 0;
}