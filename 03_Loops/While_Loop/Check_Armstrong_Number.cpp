#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n; 
    cin >> n;

    int sum=0;
    int originaln = n;   //Original input

    while(n>0){
        int lastdigit = n%10;
        sum += round(pow(lastdigit,3));
        n = n/10;
    }
    if(sum == originaln){
        cout << "Armstrong Number";
    }
    else{
        cout << "Not an Armstrong Number";
    }
    
    
    return 0;
}