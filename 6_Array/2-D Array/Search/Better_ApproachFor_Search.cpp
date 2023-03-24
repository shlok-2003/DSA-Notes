#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int target;
    cout << "Enter Target Element" << endl;
    cin >> target;

    bool flag = false;

    int x = 0, y = m - 1;
    while(x < n && y >= 0)
    {
        if(arr[x][y] == target)
        {
            flag = true;
            break;
        }
        else if(arr[x][y] > target)
        {
            y--;
        }
        else
        {
            x++;
        }
    }

    if(flag == true)
    {
        cout << "Element found at: " << endl;
        cout << "Row: " << x + 1 << " and Colmun: " << y + 1 << endl;
    }
    else{
        cout << "Element Not Found" << endl; 
    }
}