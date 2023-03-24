#include<bits/stdc++.h>
using namespace std;

int last(int arr[], int n, int i, int key){
    if(i == n)
    {
        return -1;
    }
    
    int restArray = last(arr, n, i + 1, key);
    if(restArray != -1)
    {
        return restArray;
    }

    if(arr[i] == key)
    {
        return i + 1;
    }

    return -1;
}

int first(int arr[], int n, int i, int key){
    if(i == n)
    {
        return -1;
    }

    if(arr[i] == key)
    {
        return i + 1;
    }

    return first(arr, n, i + 1, key);
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;

    cout << first(arr, n, 0, key) << endl;
    cout << last(arr, n, 0, key) << endl;
    return 0;
}