#include<iostream>
using namespace std;

int main(){
    
    int n, x=1;
    cin >> n;
    
    int sum=0;
    
    while(x <= n){
        
        sum +=x;
        x++;
    }
    cout <<sum<< endl;
    return 0;
}