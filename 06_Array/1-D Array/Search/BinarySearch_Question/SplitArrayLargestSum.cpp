#include<bits/stdc++.h>
using namespace std;

int splitArray(vector<int> &arr, int split) {
    int start = 0, end = 0;         //Find the start and end
    for(int i = 0; i < arr.size(); i++)
    {
        start = max(start, arr[i]);
        end += arr[i];
    }

    // Now we get range for solution as [start, end]. Now perform Binary Search
    // And check if the mid is compatible for making req split arrays
    while(start < end)
    {
        int mid = start + (end - start) / 2;

        //Make pieces and check
        int pieces = 1, sum = 0;
        for(auto num : arr)
        {
            if(sum + num > mid)
            {
                sum = num;
                pieces++;
            }
            else{
                sum += num;
            }
        }

        if(pieces > split)
        {
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    return start;       // Or end as end == start
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int split;
    cin >> split;

    cout << splitArray(arr, split) << endl;
    return 0;
}