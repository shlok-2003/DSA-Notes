#include<iostream>
using namespace std;
/*
Ans:    5
       456
      34567
     2345678
    123456789        
    for n=5
*/
int main(){
    int n;
    cin >> n;
    int orig_count = n;
    int count=1;
    int j;
    for(int i=1;i<=n;i++){
        int space=(n-i);
        for(j=1;j<=space;j++){
            cout << " ";
        }
        for(int k=0;k<count;k++){
            cout << k + j;
        }
        count +=2;
        cout << endl;
    }
    return 0;
}