#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int input[n];
    cout << "Enter the variable: ";
    for(int i=0;i<n;i++){
        cin >> input[i];
    }

    int iteration = 1;
    while(iteration < n){
        for(int i=0;i<(n-iteration);i++){
            if(input[i] < input[i+1]){
                int temp = input[i];
                input[i] = input[i+1];
                input[i+1] = temp;
            }
        }
        iteration++;
    }

    for(int i=0;i<n;i++){
        cout << input[i] << " ";
    }

    return 0;
}
