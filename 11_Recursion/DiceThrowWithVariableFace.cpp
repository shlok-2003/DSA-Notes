#include<bits/stdc++.h>
using namespace std;

void board(int target, int face, string ans) {
    if(target == 0)
    {
        cout << ans << endl;
        return;
    }

    for(int i = 1; i <= face && i <= target; i++)
    {
        board(target - i, face, ans + to_string(i));
    }
}

int main(){
    int target;
    cin >> target;

    int face;
    cin >> face;
    
    board(target, face, "");
    return 0;
}

// 6