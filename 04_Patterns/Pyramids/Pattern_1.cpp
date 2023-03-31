#include<iostream>
using namespace std;

/*
Ans:    *
       ***
      *****
     *******
    *********
    for n=5

*/

int main(){
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        int space=(n-i);
        for(int j=1;j<=space;j++){
            cout << " ";
        }
        for(int j=1;j<=(2*i -1);j++){
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}