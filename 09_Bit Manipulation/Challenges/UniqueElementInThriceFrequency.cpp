#include<bits/stdc++.h>
using namespace std;

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

bool getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0) ? true : false;
}

void uniqueElement(int arr[], int n)
{
    int result = 0;
    for(int i = 0; i < 64; i++)
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            if(getBit(arr[j], i))
            {
                sum++;
            }
        }
        if(sum % 3 != 0)
        {
            result = setBit(result, i);
        }
    }

    cout << result << endl;
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