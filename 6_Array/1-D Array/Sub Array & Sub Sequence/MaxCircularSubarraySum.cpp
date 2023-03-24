#include <bits/stdc++.h>
using namespace std;

/* 
    A circular array means the end of the array connects to the beginning of the array.
*/

int kadane(int arr[], int n){
    int currsum = 0, maxSum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        currsum += arr[i];
        maxSum = max(maxSum, currsum);
        if(currsum < 0)
        {
            currsum = 0;
        }
        
    }

    return maxSum;
}


int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int wrapsum, nowrapsum, totalsum = 0;

    nowrapsum = kadane(arr, n);

    for(int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -1 * arr[i];
    }

    wrapsum = totalsum - (-1 * kadane(arr, n));

    cout << max(wrapsum, nowrapsum) << endl;

    return 0;
}