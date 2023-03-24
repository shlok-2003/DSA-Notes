#include <iostream>
using namespace std;

int main(){
    int n, m, o;
    cin >> n >> m >> o;
    
    int arr[n][m][o];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < o; k++)
            {
                cin >> arr[i][j][k];
            }
        }
    }

    cout << "Result is" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            for(int k = 0; k < o; k++)
            {
                cout << arr[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }

}