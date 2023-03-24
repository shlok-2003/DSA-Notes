#include<bits/stdc++.h>
using namespace std;

void quickSort(int *arr, int start, int end) {
    if(start >= end)
    {
        return;
    }

    int low = start, high = end;
    int mid = low + (high - low) / 2;
    int pivot = arr[mid];

    while(low <= high) 
    {
        while(arr[low] < pivot)
        {
            low++;
        }

        while(arr[high] > pivot)
        {
            high--;
        }

        if(low <= high)
        {
            swap(arr[low++], arr[high--]);
        }
    }
    quickSort(arr, start, high);
    quickSort(arr, low, end);
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}