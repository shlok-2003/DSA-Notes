#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int input[n];
    cout << "Enter the variables: ";
    for(int i=0;i<n;i++){
        cin >> input[i];
    }

    for(int i=0;i<n;i++){
        int current = input[i];
        int j = i-1;
        while((input[j] < current) && j>=0){
            input[j+1] = input[j];
            j--;
        }
        input[j+1] = current;
    }

    cout << "The descending order is: ";
    for(int i=0;i<n;i++){
        cout << input[i] << " ";
    }

    return 0;
}