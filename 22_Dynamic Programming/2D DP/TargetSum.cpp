#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//? Question
//* You are given an array ‘ARR’ of ‘N’ integers and a target number, ‘TARGET’. Your task is to build an expression out of an array by adding 
//* one of the symbols '+' and '-' before each integer in an array, and then by concatenating all the integers, you want to achieve a target. 
//* You have to return the number of ways the target can be achieved.

//! This problem can be solved using the method used in Count Partition method of Subset Sum problem. I will be using the optimized method here.

int optimized(int n, int sum, vector<int> &arr) {
    vector<int> prev(sum + 1, 0), curr(sum + 1, 0);
    prev[0] = curr[0] = 1;

    if (arr[0] <= sum)
    {
        prev[arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= sum; target++)
        {
            int not_take = prev[target];
            int take = 0;
            if (arr[i] <= target)
            {
                take = prev[target - arr[i]];
            }

            curr[target] = not_take + take;
        }

        prev = curr;
    }

    return prev[sum];
}

int countPartition(int n, int diff, vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);

    //! Maths below
    //! diff = sum(s1) - sum(s2)    where s1 > s2 is must, as the difference is positive and no negative numbers are present
    //! s1 + s2 = total   ---> s1 = total - s2     -> diff = total - s2 - s2   -> 2s2 = total - diff   -> s2 = (total - diff) / 2
    //! now the edge case if that (total - diff) must be even and they must be greater than 0 so that the sum does not become negative

    //! Same as CountSubarrayWithSumK.cpp, we have used the optimized method here only

    if ((sum - diff) % 2 == 1 || sum < diff)
    {
        cout << "Not possible" << endl;
        return 0;
    }

    return optimized(n, (sum - diff) / 2, arr);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x: arr) {
        cin >> x;
    }

    int target;
    cin >> target;

    cout << "Optimized: " << countPartition(n, target, arr) << endl;
}