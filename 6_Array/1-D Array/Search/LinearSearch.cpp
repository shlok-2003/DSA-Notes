#include<iostream>
using namespace std;
/*
Take an array from user and key and find the index where the key maches 
array's variable
*/
int linearSearch(int input[],int n, int key){
    for(int i=0;i<n;i++){
        if(input[i] == key){
            return i;
        }
    }
    
    return -1;
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    cout << "Enter the variables: ";
    int input[n];
    
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    int key;
    cout << "Enter the key: ";
    cin >> key;

    cout << "Key is at the index: ";
    cout <<linearSearch(input,n,key) <<endl;

    return 0;
}