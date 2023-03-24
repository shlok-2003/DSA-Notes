#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the variables: ";
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int minIdx = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }

    cout << "The ascending order is: ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}