#include<bits/stdc++.h>
using namespace std;

void sort(int arr[], int row, int col){
    if(row == 0)
    {
        return;
    }

    if(col < row)
    {
        if(arr[col + 1] < arr[col])
        {
            swap(arr[col + 1], arr[col]);
        }
        sort(arr, row, col + 1);
    }
    else
    {
        sort(arr, row - 1, 0);
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

    sort(arr, n - 1, 0);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}