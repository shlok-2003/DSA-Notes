#include<bits/stdc++.h>
using namespace std;

void phonePad(string digit, string ans) {
    if(digit.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    int number = digit[0] - '0';
    for(int i = (number - 1) * 3; i < number * 3; i++)
    {
        char ch = (char)('a' + i);
        phonePad(digit.substr(1), (ans + ch));
    }
}

int main(){
    string digit;
    cin >> digit;

    phonePad(digit, "");
    return 0;
}