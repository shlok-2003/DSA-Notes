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
    
    int sum = 0;
    cout << "Sum of subarrays: ";

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = i; j < n; j++)
        {
            sum += input[j];
            cout << sum << " ";
        }
    }

    return 0;
}