#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int rs = 0;             //row start
    int re = n - 1;         //row end
    int cs = 0;             //column start
    int ce = m - 1;         //column end

    while(rs <= re && cs <= ce)
    {
        //row start print
        for(int col = cs; col <= ce; col++)
        {
            cout << arr[rs][col] << " ";
        }

        rs++;

        //column end print
        for(int row = rs; row <= re; row++)
        {   
            cout << arr[row][ce] << " ";
        }

        ce--;

        //row end print
        for(int col = ce; col >= cs; col--)
        {
            cout << arr[re][col] << " ";
        }

        re--;

        //column start print
        for(int row = re; row >= rs; row--)
        {   
            cout << arr[row][cs] << " ";
        }

        cs++;
    }

    return 0;
}