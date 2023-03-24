#include<bits/stdc++.h>
using namespace std;

void dice(int target, string ans) {
    if(target == 0)
    {
        cout << ans << endl;
        return;
    }

    for(int i = 1; i <= 6 && i <= target; i++)
    {
        dice(target - i, ans + to_string(i));
    }
}

int main(){
    int target;
    cin >> target;

    dice(target, "");
    return 0;
}