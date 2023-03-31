#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the odd integer: ";
    cin >> n;
    int mid= n/2 + 1;

    for(int i=1 ;i<=n;i++){
        for(int j=1;j<=n;j++){
            
            if(i==1 || i==mid || i==n || (j==1 && i>mid) || (j==n && i<mid)){
                cout << "* ";
            }
            else{
                cout << "  ";
            }
        }
        cout << endl;
    }

    return 0;
}