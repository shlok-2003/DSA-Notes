#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    stack<char> s;
    for(int i = 0; i < n; i++)
    {
        char ch = str[i];
        s.push(ch);
    }

    string ans = "";
    while(!s.empty())
    {
        char ch = s.top();
        ans.push_back(ch);
        s.pop();
    }

    cout << ans << endl;
}