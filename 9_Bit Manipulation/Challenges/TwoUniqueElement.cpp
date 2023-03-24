#include<bits/stdc++.h>
using namespace std;

bool getBit(int num, int pos)
{
    return ((num & (1 << pos)) != 0) ? true : false;
}

void uniqueElement(int arr[], int n)
{
    int xorsum = 0;
    for(int i = 0; i < n; i++)
    {
        xorsum = xorsum ^ arr[i];
    }

    int temp = xorsum;
    int setBit = 0;
    int pos = 0;
    while(setBit != 1)
    {   
        setBit = xorsum & 1;
        pos++;
        xorsum = (xorsum >> 1);
    }

    int newxor = 0;

    for(int i = 0; i < n; i++)
    {
        if(getBit(arr[i], pos - 1))
        {
            newxor = (newxor ^ arr[i]);
        }
    }

    cout << newxor << endl;
    cout << (newxor ^ temp) << endl;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    uniqueElement(arr, n);
    return 0;
}