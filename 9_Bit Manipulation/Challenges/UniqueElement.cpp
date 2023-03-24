#include<bits/stdc++.h>
using namespace std;

int uniqueElement(int arr[], int n)
{
    int temp = 0;
    for(int i = 0; i < n; i++)
    {
        temp = temp ^ arr[i];
    }

    return temp;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << uniqueElement(arr, n) << endl;
    return 0;
}