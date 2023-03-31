/* CODECHEF.com
The weather report of Chefland is Good if the number of sunny days in a week is strictly greater than the number of rainy days.

Given 77 integers A1,A2,A3,A4,A5,A6,A7A1,A2,A3,A4,A5,A6,A7 where Ai=1Ai=1 denotes that the ithith day of week in Chefland is a sunny day, Ai=0Ai=0 denotes that the ithith day in Chefland is a rainy day. Determine if the weather report of Chefland is Good or not.

Input Format
First line will contain TT, number of testcases. Then the testcases follow.
Each testcase contains of a single line of input, 77 space separated integers A1,A2,A3,A4,A5,A6,A7A1,A2,A3,A4,A5,A6,A7.
Output Format
For each testcase, print "YES" if the weather report of Chefland is Good, otherwise print "NO". Print the output without quotes.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).

Constraints
1≤T≤201≤T≤20
0≤Ai≤10≤Ai≤1
Sample Input 1 
4
1 0 1 0 1 1 1
0 1 0 0 0 0 1
1 1 1 1 1 1 1
0 0 0 1 0 0 0
Sample Output 1 
YES
NO
YES
NO
Explanation
Test case 11: The number of sunny days is 55 and the number of rainy days is 22. Hence the weather report of Chefland is Good.

Test case 22: The number of sunny days is 11 and the number of rainy days is 66. Hence the weather report of Chefland is not Good.
 */

#include <iostream>
using namespace std;

int main() {
	int t, a[7], i;
	cin >> t;
	
	while(t--)
	{
        for(i = 0; i < 7; i++)
        {
            cin >> a[i];
        }
        
        int s = 0; 
        int r = 0;
        
        for(i = 0; i < 7; i++)
        {
            if(a[i] == 1)
            {
                s++;
            }
            if(a[i] == 0)
            {
                r++;
            }
        }
        
        if(s > r)
        {
            cout << "YES" << endl;
        }
        else if(s < r)
        {
            cout << "NO" << endl;
        }
    }
	return 0;
}
