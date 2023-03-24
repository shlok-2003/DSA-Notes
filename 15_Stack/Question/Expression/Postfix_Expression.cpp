#include <bits/stdc++.h>
using namespace std;

int evaluation(string str) {
    stack<int> s;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
            s.push(str[i] - '0');
        else
        {
            int top2 = s.top();
            s.pop();
            int top1 = s.top();
            s.pop();

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
        }
    }

    return s.top();
}

int main() {
    string str;
    cin >> str;

    cout << evaluation(str) << endl; 
}