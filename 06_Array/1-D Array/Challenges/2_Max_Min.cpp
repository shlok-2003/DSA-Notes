#include<iostream>
#include<climits>
using namespace std;
/*
Take the number of variable from user and give the maximum and minimum
of them
*/
int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int input[n];
    for(int i=0;i<n;i++){
        cin >> input[i];
    }
    int maxNo = INT_MIN;
    int minNo = INT_MAX;

    for(int i=0;i<n;i++){
        maxNo = max(maxNo,input[i]);
        minNo = min(minNo,input[i]);
    }
    cout << maxNo << " " << minNo <<endl;
    
    return 0;
}