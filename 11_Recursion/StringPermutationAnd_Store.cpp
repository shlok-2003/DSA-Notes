#include<bits/stdc++.h>
using namespace std;

void permutation(string str, vector<string> &display, string ans) {
    if(str.size() == 0)
    {
        display.push_back(ans);
        return;
    }

    char ch = str[0];
    for(int i = 0; i <= ans.size(); i++)
    {
        string first = ans.substr(0, i);
        string second = ans.substr(i);
        permutation(str.substr(1), display, (second + ch + first));
    }
}

int main(){
    string str;
    cin >> str;

    vector<string> display;
    permutation(str, display, "");
    
    for(int i = 0; i < display.size(); i++)
    {
        cout << display[i] << endl;
    }
    return 0;
}