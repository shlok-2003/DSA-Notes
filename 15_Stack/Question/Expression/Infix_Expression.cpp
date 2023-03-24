#include <bits/stdc++.h>
using namespace std;

int evaluation(string str) {
    stack<int> s;
    stack<char> e;

    for(int i = 0; i < str.size(); i++)
    {
        char c = str[i];

        if(c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
            e.push(c);
        else
        {
            if(s.empty())
                s.push(c - '0');
            else
            {
                int top1 = s.top();
                s.pop();
                int top2 = c - '0';

                switch(str[i])
                {
                    case '+' :  s.push(top1 + top2);
                                break;
                    case '-' :  s.push(top1 - top2);
                                break;
                    case '*' :  s.push(top1 * top2);
                                break;
                    case '/' :  s.push(top1 / top2);
                                break;
                    case '^' :  s.push(round(pow(top1, top2)));
                                break;
                }
                e.pop();
            }
        }
    }

    return s.top();
}

int main() {
    string str;
    cin >> str;

    cout << evaluation(str) << endl;
}