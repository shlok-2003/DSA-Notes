#include<bits/stdc++.h>
using namespace std;
#define mod 10000000007


long long count(int target, int face, string ans) {
    if(target == 0)
    {
        return 1;
    }

    int count1 = 0;
    for(int i = 1; i <= face && i <= target; i++)
    {
        count1 += count(target - i, face, ans + to_string(i));
    }

    return count1 % mod;
}

int main(){
    int target;
    cin >> target;

    int face;
    cin >> face;

    cout << count(target, face, "") << endl;
    return 0;
}