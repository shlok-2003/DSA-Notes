#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int input[n];
    cout << "Enter the variables: ";
    for(int i=0;i<n;i++){
        cin >> input[n];
    }

    int repetition = 1;
    int ans = INT_MIN;

    for(int i=0;i<n;i++){
        for(int j =i+1;j<n;j++){
            if(input[i] == input[j]){
                repetition+=1;
            }
            else{
                repetition = 1;
            }
            ans = max(ans, repetition);
        }
    }
    cout << ans << endl;

    return 0;
}