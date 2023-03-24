/* CODECHEF.com
You have three shoes of the same size lying around. Each shoe is either a left shoe (represented using 00) or a right shoe (represented using 11). Given AA, BB, CC, representing the information for each shoe, find out whether you can go out now, wearing one left shoe and one right shoe.

Input Format
The first line contains an integer TT, the number of test cases. Then the test cases follow.
Each test case contains a single line of input, three integers AA, BB, CC.
Output Format
For each test case, output in a single line the answer: 11 if it's possible to go out with a pair of shoes and 00 if not.

Constraints
1≤T≤81≤T≤8
0≤A,B,C≤10≤A,B,C≤1
Sample Input 1 
3
0 0 0
0 1 1
1 0 1
Sample Output 1 
0
1
1
Explanation
Test Case 11: Since there's no right shoe, it's not possible to go out with a pair of shoes.

Test Case 22: It's possible to go out with a pair of shoes wearing the first and last shoes.

Test Case 33: It's possible to go out with a pair of shoes wearing the first and second shoes.
*/

#include <iostream>
using namespace std;

int main() {
	int t, a, b, c;
	cin >> t;
	
	while(t--)
	{
        cin >> a >> b >> c;
        
        if( (a + b + c) == 0 || (a + b + c) == 3)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << "1" << endl;
            
        }
	}
	return 0;
}
