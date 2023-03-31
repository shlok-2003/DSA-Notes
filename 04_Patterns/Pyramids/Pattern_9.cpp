#include<iostream>
#include<iomanip>
using namespace std;
/*
Ans:        1
          2 3 4
        5 6 7 8 9 
   10 11 12 13 14 15 16
17 18 19 20 21 22 23 24 25 
for n=5
*/
int main(){
    int n;
    cin >> n;
    int count=1;

    for(int i=1;i<=n;i++){
        int space=(n-i);
        for(int j=1;j<=space;j++){
            cout << " ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout << count;
            count++;
        }
        cout <<endl;
    }
}