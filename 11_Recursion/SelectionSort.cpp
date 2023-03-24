#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int row, int col, int max) {
    if(row == 0)
    {
        return;
    }

    if(col < row)
    {
        if(arr[col] > arr[max])
        {
            sort(arr, row, col + 1, col);
        }
        else
        {
            sort(arr, row, col + 1, max);
        }
    }
    else
    {
        swap(arr[row - 1], arr[max]);
        sort(arr, row - 1, 0, 0);
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

    sort(arr, n, 0, 0);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}