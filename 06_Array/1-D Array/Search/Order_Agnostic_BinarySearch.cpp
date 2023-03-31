#include<bits/stdc++.h>
using namespace std;

int OrderAgnosticBS(int arr[], int n, int target, bool Order) {
    int start = 0, end = n - 1;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }

        if(Order)
        {
            if(arr[mid] > target)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        else
        {
            if(arr[mid] > target)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    bool Asc;       //! Check if content is ascending or descending 
    cin >> Asc;     

    cout << OrderAgnosticBS(arr, n, target, Asc) << endl;
    return 0;
}