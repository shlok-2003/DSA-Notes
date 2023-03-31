#include<iostream>
using namespace std;
/*
Ans:    5
       444
      33333
     2222222
    111111111     
    for n=5
*/
int main(){
    int n;
    cin >> n;
    int count = n;
    for(int i=1;i<=n;i++){
        int space=(n-i);
        for(int j=1;j<=space;j++){
            cout << " ";
        }
        for(int j=1;j<=(2*i-1);j++){
            cout << count;
        }
        count--;
        cout << endl;
    }
    return 0;
}