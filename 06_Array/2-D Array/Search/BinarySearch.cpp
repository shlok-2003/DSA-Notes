#include<bits/stdc++.h>
using namespace std;

int ColumnSearch(vector<vector<int>> &arr, int target, int Rmid, int Column) {
    int Cstart = 0, Cend = arr[0].size() - 1;

    if(target < arr[Rmid][Cstart])
    {
        return -1;
    }
    else if(target > arr[Rmid][Cend])
    {
        return 1;
    }

    while(Cstart <= Cend)
    {
        int Cmid = Cstart + (Cend - Cstart) / 2;
        if(arr[Rmid][Cmid] == target)
        {
            return 0;
        }
        else if(arr[Rmid][Cmid] > target)
        {
            Cend = Cmid - 1;
        }
        else{
            Cstart = Cmid + 1;
        }
    }

    return 2;
}

vector<int> binarySeach(vector<vector<int>> &arr, int target) {
    int Rstart = 0, Rend = arr.size() - 1;

    vector<int> ans;
    while(Rstart <= Rend)
    {
        int Rmid = Rstart + (Rend - Rstart) / 2;
        int Column = -2;

        int flag = ColumnSearch(arr, target, Rmid, Column);
        if(flag == 0)
        {
            ans.push_back(Rmid);
            ans.push_back(Column);
            return ans;
        }
        else if(flag == -1)
        {
            Rstart = Rmid + 1;
        }
        else if(flag == 1)
        {
            Rend = Rmid - 1;
        }
        else
        {
            break;
        }

        ans.push_back(-1);      // If ans is not present
        return ans;
    }
}

int main(){
    int m, n;
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int target;
    cin >> target;

    vector<int> ans = binarySeach(arr, target);
    for(int i = 0; i < 2; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}