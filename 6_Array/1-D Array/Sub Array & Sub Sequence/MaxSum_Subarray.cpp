#include <bits/stdc++.h>
using namespace std;

int main(){
    
/*
    int n;
    cin >> n;

    O(n ^ 3) solution, very bad complexity
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0, maxSum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        for(int j = i; j < n; j++)
        {
            sum = 0;
            for(int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << endl;

*/

/*  O(n ^ 2) solution, complexity is all right
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0, maxSum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum << endl;
*/
/*
    O(n ^ 2) solution Cumalative Sum Approach
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int CumSum[n + 1];
    CumSum[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        CumSum[i] = CumSum[i - 1] + arr[i - 1];
    }

    int maxSum = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        int sum = 0;
        for(int j = 0; j < i; j++)
        {
            sum = CumSum[i] - CumSum[j];
            maxSum = max(sum, maxSum);
        }
    }
                                    //for explanation, see all output
    cout << "Answer is: " << maxSum << endl;

*/
    //! O(n) solution: KADANE's Algorithm

    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }

    int currentSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        maxSum = max(currentSum, maxSum);
        if(currentSum < 0)
        {
            currentSum = 0;
        }
    }

    cout << maxSum << endl;


    return 0;
}