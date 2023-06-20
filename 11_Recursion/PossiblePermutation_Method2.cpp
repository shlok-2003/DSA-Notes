#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> ans;

void helper(vector<int> &arr, int n, vector<int> &mark, vector<int> tmp) {
    if(tmp.size() == arr.size())
    {
        ans.push_back(tmp);
        return;
    }

    for(int i = 0; i < n; i++)
    {
        if(!mark[i])
        {
            mark[i] = 1;
            tmp.push_back(arr[i]);

            helper(arr, n, mark, tmp);

            tmp.pop_back();
            mark[i] = 0;
        }
    }
}

vector<vector<int>> possiblePermutation(vector<int> &arr, int n) {
    ans.clear();
    vector<int> mark(n, 0);
    helper(arr, n, mark, vector<int>{});

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr)   cin >> i;

    vector<vector<int>> permutation = possiblePermutation(arr, n);

    cout << "The possible permutations are: \n" << endl;
    for(const auto &it : permutation)
    {
        for(const int &num : it) 
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
