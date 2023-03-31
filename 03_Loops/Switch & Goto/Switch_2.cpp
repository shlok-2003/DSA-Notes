#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    char oprator;
    cin >> n1 >> oprator >> n2; 

    switch(oprator){
        case '+':
        cout << n1 + n2 << endl;
        break;

        case '-':
        cout << n1 - n2 << endl;
        break;

        case '*':
        cout << n1 * n2 << endl;
        break;

        case '/':
        cout << n1 / n2 << endl;
        break;

        default:
        cout << "Cannot be calculated" << endl;
        break;
    }


return 0;
}