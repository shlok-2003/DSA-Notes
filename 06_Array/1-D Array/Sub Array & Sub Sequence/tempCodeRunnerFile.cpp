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