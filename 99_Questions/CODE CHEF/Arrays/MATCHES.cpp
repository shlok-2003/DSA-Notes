/* CODECHEF.com
Chef's son Chefu found some matches in the kitchen and he immediately starting playing with them.

The first thing Chefu wanted to do was to calculate the result of his homework — the sum of AA and BB, and write it using matches. Help Chefu and tell him the number of matches needed to write the result.

Digits are formed using matches in the following way: 

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first and only line of each test case contains two space-separated integers AA and BB.
Output
For each test case, print a single line containing one integer — the number of matches needed to write the result (A+BA+B).

Constraints
1≤T≤1,0001≤T≤1,000
1≤A,B≤1061≤A,B≤106
Sample Input 1 
3
123 234
10101 1010
4 4
Sample Output 1 
13
10
7
Explanation
Example case 1: The result is 357357. We need 55 matches to write the digit 33, 55 matches to write the digit 55 and 33 matches to write the digit 77.

Example case 2: The result is 1111111111. We need 22 matches to write each digit 11, which is 2⋅5=102⋅5=10 matches in total.
*/

#include <iostream>
using namespace std;

int main() {
	int t, a, b;
	cin >> t;
	
	while(t--)
	{
        cin >> a >> b;
        a = a + b;
        int arr[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
        int temp = 0;
        int total = 0;
        
        while(a > 0)
        {
            temp = a % 10;
            a = a / 10;
            total += arr[temp];
        }

        cout << total << endl;
	}
	return 0;
}
