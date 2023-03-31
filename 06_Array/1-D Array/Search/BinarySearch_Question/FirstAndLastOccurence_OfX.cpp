#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int target, bool flag) {
    int ans = -1;
    int start = 0, end = 8 - 1;             //!Since size of array is 8

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target)
        {
            ans = mid;
            if(flag)            //!Means finding first element
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n = 8;
    int arr[] = {5, 7, 7, 7, 7, 8, 8, 10};
    
    int target = 7;
    vector<int> ans = {-1, -1};
    
    ans[0] = binarySearch(arr, target, true);
    if(arr[0] != -1)
    {
        ans[1] = binarySearch(arr, target, false);
    }

    //!Display
    for(int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}