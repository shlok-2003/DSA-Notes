#include<iostream>
using namespace std;
/*
Take two numbers from user and the number between them should be the variables in array
*/
int arrray_size(int n1, int n2){
    int number = 0;
    for(int z=n1;z<=n2;z++){
        number++;
    }

    return number;
}

int main(){
    int n1, n2;
    cout << "Enter starting number: ";
    cin >> n1;
    cout << "Enter ending number: ";
    cin >> n2;

    int input[arrray_size(n1, n2)];
    int temp = n1;
    for(int i=0;i<arrray_size(n1, n2);i++){
        
        input[i] = temp;
        temp++;
    }

    for(int i=0;i<arrray_size(n1, n2);i++){
        cout << input[i] << " ";
    }

    return 0;
}