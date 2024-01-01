#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//! This problem is solved in most optimized way. Refer to SubsetSumEqualsK.cpp for other methods 

bool helper(vector<int> &arr, int k, int n) {
    vector<bool> curr(k+1, false), prev(k+1, false);

    curr[0] = prev[0] = true;
    if(arr[0] <= k)     prev[arr[0]] = true;        //? Base condition

    for(int i = 1; i < n; i++)
    {
        for(int target = 1; target <= k; target++)
        {
            int not_take = prev[target];
            int take = 0;
            if(arr[i] <= target)    take = prev[target-arr[i]];

            curr[target] = take | not_take;
        }

        prev = curr;
    }

    return prev[k];
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(auto &i : arr)
    {
        cin >> i;
    }

    int sum;
    cin >> sum;

    if(sum % 2 == 1) {
        cout << "false" << endl;
        return 0; 
    }

    sum /= 2;
    if(helper(arr, sum, n)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}
