#include<bits/stdc++.h>
using namespace std;

void permutation(string str, string ans)
{
    if(str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string rest = str.substr(0, i) + str.substr(i + 1);
        permutation(rest, (ans + ch));
    }
}

int main(){
    string str;
    cin >> str;

    permutation(str, "");
    return 0;
}