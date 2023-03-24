#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int ans= 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j > i)
                swap(arr[i][j], arr[j][i]);
        }

        /*
        OR 
        More better approach is:
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                swap(arr[i][j], arr[j][i])
            }
        }
        */
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}