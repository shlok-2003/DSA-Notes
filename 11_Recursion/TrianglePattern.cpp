#include <bits/stdc++.h>
using namespace std;

void print(int row, int col){
    if(row == 0)
    {
        return;
    }

    if(col <= row)
    {
        cout << "* ";
        print(row, col + 1);
    }
    else{
        cout << endl;
        print(row - 1, 1);
    }
}

int main(){
    int row;
    cin >> row;

    print(row, 1);
    return 0;
}