#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int multiply_By=1;
    
    while(multiply_By<=10){
        
        cout << x <<"x"<< multiply_By <<"="<< x*multiply_By <<endl;
        multiply_By++;
        
    }
    
    
    return 0;
}