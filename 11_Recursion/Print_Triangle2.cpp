#include<bits/stdc++.h>
using namespace std;

void print(int row, int col){
    if(row == 0)
    {
        return;
    }

    if(col <= row)
    {
        print(row, col + 1);
        cout << "* ";
    }
    else{
        print(row - 1, 1);
        cout << endl;
    }
}

int main(){
    int row;
    cin >> row;

    print(row, 1);
    return 0;
}