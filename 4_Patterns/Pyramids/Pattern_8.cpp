#include<iostream>
using namespace std;
/*
Ans:    5
       654
      76543
     8765432
    987654321
    for n=5   
*/
int main(){
    int n;
    cin >> n;
    int count = 1;
int j;
    for(int i=1;i<=n;i++){
        int space = (n-i);
        for(j=0;j<space;j++){
            cout << " ";
        }
        for(int k=count;k>0;k--){
            cout << k + j;
        }
        count +=2;
        cout << endl;
    }
}