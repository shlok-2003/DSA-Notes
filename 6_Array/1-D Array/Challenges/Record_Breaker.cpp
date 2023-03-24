#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int input[n+1];
    input[n] = -1;

    cout << "Enter the variables: ";
    for(int i=0;i<n;i++){
        cin >> input[i];
    }

    if(n == 1){
        cout << "1" << endl;
        return 0;
    }

    int ans = 0;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        if(input[i] > mx && input[i] > input[i+1]){
            ans++;
        }
        ans = max(input[i], mx);
    }

    cout << ans << endl;

    return 0;
}