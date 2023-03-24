/* CODECHEF.com
Read problem statements in Russian and Mandarin Chinese.
Given the time control of a chess match as a+ba+b, determine which format of chess out of the given 44 it belongs to.

1)1) Bullet if a+b<3a+b<3

2)2) Blitz if 3≤a+b≤103≤a+b≤10
3)3) Rapid if 11≤a+b≤6011≤a+b≤60

4)4) Classical if 60<a+b60<a+b
Input Format
First line will contain TT, number of testcases. Then the testcases follow.
Each testcase contains a single line of input, two integers a,ba,b.
Output Format
For each testcase, output in a single line, answer 11 for bullet, 22 for blitz, 33 for rapid, and 44 for classical format.

Constraints
1≤T≤11001≤T≤1100
1≤a≤1001≤a≤100
0≤b≤100≤b≤10
Sample Input 1 
4
1 0
4 1
100 0
20 5
Sample Output 1 
1
2
4
3
Explanation
TestCase 11: Since a+b=1<3a+b=1<3, it belongs to bullet format.

TestCase 22: Since 3≤(a+b=5)≤103≤(a+b=5)≤10, it belongs to blitz format.
*/

#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	cin >> t;
	
	while(t--)
	{
        cin >> a >> b;
        
        if((a + b) < 3)
        {
            cout << "1" << endl;
        }
        else if((a + b) <= 10)
        {
            cout << "2" << endl;
        }
        else if((a + b) <= 60)
        {
            cout << "3" << endl;
        }
        else
        {
            cout << "4" << endl;   
        }
    }
	return 0;
}
