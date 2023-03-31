#include<iostream>
using namespace std;

int binarySearch(int input[], int n, int key){
    int s = 0;
    int e = n ;
    while(s <= e){
        int mid = (s + e)/2;

        if(input[mid] == key){
            return mid;
        }
        else if(input[mid] > key){
            e = mid - 1;
        }
        else{
            s = mid + 1;
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
    cout <<binarySearch(input,n,key) <<endl;

    return 0;
}