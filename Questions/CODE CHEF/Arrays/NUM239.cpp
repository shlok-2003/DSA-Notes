/* CODECHEF.com
Vasya likes the number 239239. Therefore, he considers a number pretty if its last digit is 22, 33 or 99.

Vasya wants to watch the numbers between LL and RR (both inclusive), so he asked you to determine how many pretty numbers are in this range. Can you help him?

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains two space-separated integers LL and RR.
Output
For each test case, print a single line containing one integer — the number of pretty numbers between LL and RR.

Constraints
1≤T≤1001≤T≤100
1≤L≤R≤1051≤L≤R≤105
Subtasks
Subtask #1 (100 points): original constraints

Sample Input 1 
2
1 10
11 33
Sample Output 1 
3
8
Explanation
Example case 1: The pretty numbers between 11 and 1010 are 22, 33 and 99.

Example case 2: The pretty numbers between 1111 and 3333 are 1212, 1313, 1919, 2222, 2323, 2929, 3232 and 3333.
*/

#include <iostream>
using namespace std;

int main() {
	int t, l, r;
	cin >> t;
	
	while(t--)
	{
        cin >> l >> r;
        int count = 0;
        
        for(int i = l; i <= r; i++)
        {
            if((i % 10 == 2 )|| (i % 10 == 3) || (i % 10 == 9))
            {
                count++;
            }
        }
        cout << count << endl;
	}
	return 0;
}
