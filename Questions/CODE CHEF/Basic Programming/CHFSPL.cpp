/* CODECHEF.com
Chef has three spells. Their powers are AA, BB, and CC respectively. Initially, Chef has 00 hit points, and if he uses a spell with power PP, then his number of hit points increases by PP.

Before going to sleep, Chef wants to use exactly two spells out of these three. Find the maximum number of hit points Chef can have after using the spells.

Input Format
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains three space-separated integers AA, BB, and CC.
Output Format
For each test case, print a single line containing one integer — the maximum number of hit points.

Constraints
1≤T≤1041≤T≤104
1≤A,B,C≤1081≤A,B,C≤108
Subtasks
Subtask #1 (100 points): original constraints

Sample Input 1 
2
4 2 8
10 14 18
Sample Output 1 
12
32
Explanation
Example case 1: Chef has three possible options:

Use the first and second spell and have 4+2=64+2=6 hitpoints.
Use the second and third spell and have 2+8=102+8=10 hitpoints.
Use the first and third spell and have 4+8=124+8=12 hitpoints.
Chef should choose the third option and use the spells with power 44 and 88 to have 1212 hitpoints.

Example case 2: Chef should use the spells with power 1414 and 1818.
*/

#include <iostream>
#include <climits>
using namespace std;

int main() {
	int t, a, b, c;
	cin >> t;
	
	while(t--)
	{
        cin >> a >> b >> c;
        int x = 0, y = 0;
        
        x = a + b;
        y = b + c;
        
        if(x > y)
        {
            y = a + c;
            x = max(x, y);
            cout << x << endl;
        }
        else
        {
            x = a + c;
            y = max(x, y);
            cout << y << endl;
        }
	}
	return 0;
}
